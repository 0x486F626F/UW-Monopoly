#include "board.h"
#include "dice.h"
#include "cell.h"
#include "group.h"
#include "facility.h"
#include "property.h"
#include "textdisplay.h"
#include "xdisplay.h"
#include "player.h"
#include "behavior.h"

#include "strategy.h"
#include "human.h"

#include "buyproperty.h"
#include "collectrent.h"
#include "sendtotimline.h"
#include "timline.h"
#include "slc.h"
#include "nh.h"
#include "modifymoney.h"
#include "rollrent.h"
#include "rollrimcup.h"
#include "showmsg.h"
#include "tuition.h"

#include <iostream>
#include <sstream>
#include <fstream>
#include <cstdlib>
using namespace std;

const string names[] = {"Goose", "GRT Bus", "Tim Hortons Doughut", "Professor", "Student", "Money", "Laptop", "Pink tie"};
const string tabs[] = {"			", "			", "	", "		", "			", "			", "			", "		"};
const char inits[] = {'G', 'B', 'D', 'P', 'S', '$', 'L', 'T'};

/*****Instance*****/
void Board::cleanInstance() { delete instance; }
Board *Board::getInstance(const string save, const bool testing) { //{{{
	if(!instance) {
		instance = new Board(save, testing);
		atexit(cleanInstance);
	}
	return instance;
} //}}}
Board *Board::instance = NULL;

/*****Constructor*****/
Board::Board(const string save, const bool test) : savefile(save), testing(test) { //{{{
	bh = Behavior::getInstance();
	numPlayer = numCell = numGroup = 0;
	td = new TextDisplay;
} 
Board::~Board() {
	delete td;
	for(int i = 0; i < numCell; i ++)
		delete cells[i];
	for(int i = 0; i < numPlayer; i ++)
		delete players[i];
	for(int i = 0; i < groups.size(); i ++)
		delete groups[i];
} //}}}

/*****setGame*****/
void Board::loadMap(const string &mapfile) { //{{{
	string tmp;
	ifstream stream(mapfile.c_str());
	getline(stream, tmp);
	istringstream str(tmp);
	str >> width >> height;
	numCell = width * 2 + height * 2 - 4;

	for(int i = 0; i < numCell; i ++) {
		int cost, n, rent;
		string name, group;

		getline(stream, name);
		getline(stream, group);

		Cell *p; 
		if(group == "NONE") p = new Facility(i, name);
		else {
			p = new Property(i, name);	
			bool found = false;
			for(vector <Group*>::iterator i = groups.begin(); i != groups.end(); i ++)
				if((*i)->getName() == group) { 
					(*i)->addProperty(dynamic_cast <Property*> (p)); 
					found = true;
				}
			if(!found) {
				groups.push_back(new Group(numGroup ++, group));
				(*(groups.end() - 1))->addProperty(dynamic_cast <Property*> (p));
			}
		}

		stream >> cost;
		if(cost) {
			stream >> cost >> rent;
			p->setCost(cost);
			p->addRent(rent);
			p = new BuyProperty(*p);
			if(rent) p = new CollectRent(*p);
		}

		stream >> cost;
		if(cost) {
			stream >> cost >> n;
			p->setCostImprove(cost);
			while(n --) {
				stream >> rent;
				p->addRent(rent);
			}
		}


		stream >> n;
		for(int i = 0; i < n; i ++) {
			string eventname;
			stream >> eventname;
			if(eventname == "Timline") {
				int fee;
				string itemname;
				stream >> fee >> itemname;
				p = new TimLine(*p, fee, itemname);
			}
			else if(eventname == "SendToBlock") {
				int id;
				stream >> id;
				p = new SendToTimLine(*p, id);
			}
			else if(eventname == "SLC") {
				int id;
				stream >> id;
				p = new SLC(*p, id);
			}
			else if(eventname == "NH") {
				p = new NH(*p);
			}
			else if(eventname == "ModifyMoney") {
				int m;
				stream >> m;
				p = new ModifyMoney(*p, m);
			}
			else if(eventname == "RollRent") {
				p = new RollRent(*p);
			}
			else if(eventname == "ShowMsg") {
				string msg;
				getline(stream, msg);
				msg.erase(msg.begin());
				p = new ShowMsg(*p, msg);
			}
			else if(eventname == "Tuition") {
				p = new Tuition(*p);
			}
			else if(eventname == "RollRimCup") {
				p = new RollRimCup(*p);
			}
		}

		cells.push_back(p);

		getline(stream, tmp);
		getline(stream, tmp);
	}
	for(int i = 0; i < width; i ++) {
		cells[i + width + height - 2]->setX(i * 50);
		cells[i + width + height - 2]->setY(0);
		cells[width - i - 1]->setX(i*50);
		cells[width - i - 1]->setY((height - 1)*50);
	}
	for(int i = 0; i < height - 2; i ++) {
		cells[width + height - 3 - i]->setX(0);
		cells[width + height - 3 - i]->setY(i * 50 + 50);
		cells[width * 2 + height - 2 + i]->setX((width - 1) * 50);
		cells[width * 2 + height - 2 + i]->setY(i * 50 + 50);
	}
	xd = XDisplay::getInstance(width, height);
	xd->drawLogo();
} //}}}


void Board::saveGame(const string saveFile) { //{{{
	ofstream stream(("save/" + saveFile).c_str());
	stream << numPlayer << endl;
	for(int i = 1; i <= numPlayer; i ++) {
		int now = (nowPlayer + i) % numPlayer;
		stream << players[now]->getName() << " " << players[now]->getMoney() << " " << players[now]->getCurrentCell()->getID();
		if(players[now]->getCurrentCell()->getID() == 10) cout << " " << (players[now]->getBlock() != 0);
		if(players[now]->getBlock() != 0) cout << " " << players[now]->getBlock();
		stream << endl;
	}
	for(int i = 0; i < numCell; i ++) 
		if(cells[i]->getGroup()) {
			stream << cells[i]->getName() << " ";
			if(cells[i]->isSold()) stream << cells[i]->getOwner()->getName() << " ";
			else stream << "BANK ";
			if(cells[i]->isMortgaged()) stream << " -1" << endl;
			else stream << cells[i]->getLevel() << endl;
		}
} //}}}

void Board::initGame() { //{{{
	string mapfile = "maps/uw.map";
	Dice::getInstance(numDice = 2);
	loadMap(mapfile);	

	while(1) {
		cout << "Input the number of players (2~6)" << endl;
		cin >> numPlayer;
		if(numPlayer >= 2 && numPlayer <= 6) break;
	}

	for(int i = 0; i < numPlayer; i ++) {
		players.push_back(new Player(i, ""));
		//cout << "Human player or Computer? (H/C)" << endl;
		players[i]->setStrategy(0);

		string name;
		cout << "Input name:" << endl;
		cin >> name;
		if(name == "Bruce") {
			cout << "Welcome to the game, Master Wayne!" << endl;
			players[i]->setName("Bruce");
			players[i]->setInit(name[0]);
			players[i]->setMoney(15000);
			for(int j = 0; j < numCell; j ++)
				if(cells[j]->getName() == "MC" || cells[j]->getName() == "DC")
					bh->buyProperty(players[i], cells[j]);
		}
		else {
		   cout << "Welcome to the game, Player " << name << endl;
			players[i]->setName(name);
			players[i]->setInit(name[0]);
			players[i]->setMoney(1500);
		}
		players[i]->setLeftRoll(1);
		cells[0]->addPlayer(players[i]);
	}
} //}}}

void Board::loadGame(const string saveFile) { //{{{
	string mapfile = "maps/uw.map";
	Dice::getInstance(numDice = 2);
	loadMap(mapfile);	

	cout << saveFile << endl;
	cout << "Save game re-initializing"
	ifstream stream(saveFile.c_str());
	stream >> numPlayer;

	for(int i = 0; i < numPlayer; i ++) {
		players.push_back(new Player(i, ""));
		players[i]->setStrategy(0);

		string name;
		int money, position;

		stream >> name;
		players[i]->setName(name);
		players[i]->setInit(name[0]);

		stream >> money;
		players[i]->setMoney(money);

		stream >> position;
		cells[position]->addPlayer(players[i]);
		if(position == 10) {
			int block;
			stream >> block;
			if(block) {
				stream >> block;
				players[i]->setBlock(block + 1);
			}
		}

		players[i]->setLeftRoll(1);
	}

	string pName;
	while(stream >> pName) {
		cout << pName << endl;
		string owner;
		stream >> owner;
		Player *p = getPlayer(owner);
		int level;
		stream >> level;
		if(owner != "BANK")
			for(int j = 0; j < numCell; j ++) 
				if(cells[j]->getName() == pName) {
					bh->buyProperty(p, cells[j]);
					if(level == -1) cells[j]->mortgage();
					else cells[j]->setLevel(level);
				}
	}
} //}}}

bool Board::gameEnd() {
	int cnt = 0;
	for(int i = 0; i < numPlayer; i ++)
		cnt += !players[i]->isBankrupted();
	return cnt == 1;
}

/*****printBoard*****/
void Board::printBoard() {
	for(int i = 0; i < numCell; i ++) {
		cells[i]->drawXImage();
	}
	td->printAll(width, height, cells);
}

void Board::movePlayerTo(const int idPlayer, const int idCell, const bool callEvent) {
	cells[idCell]->movePlayer(players[idPlayer]);
	if(callEvent) cells[idCell]->event(players[idPlayer]);
}

void Board::movePlayerForward(const int idPlayer, const int step) {
	int goal = players[idPlayer]->getCurrentCell()->getID() + step;
	if(goal >= numCell) {
		cout << "Collected your OSAP" << endl << players[idPlayer]->getName() << " receives $200" << endl;
		players[idPlayer]->addMoney(200);
	}
	movePlayerTo(idPlayer, (goal + numCell) % numCell);
}

/*****startGame*****/
void Board::startGame() {
	if(savefile.length() > 0) loadGame("save/" + savefile);
	else initGame();
	bh->setTesting(testing);

	printBoard();
	for(nowPlayer = 0; !gameEnd(); nowPlayer = (nowPlayer + 1) % numPlayer) 
		if(!players[nowPlayer]->isBankrupted()) {
			cout << players[nowPlayer]->getName() << "'s turn" << endl;
			bh->playRound(players[nowPlayer]);
		}
	cout << "Game Over" << endl;
}

Player* Board::getPlayer(const string &name) {
	for(int i = 0; i < numPlayer; i ++)
		if(players[i]->getName() == name) return players[i];
	return NULL;
}
