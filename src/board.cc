#include "board.h"
#include "dice.h"
#include "cell.h"
#include "group.h"
#include "facility.h"
#include "property.h"
#include "textdisplay.h"
//#include "xdisplay.h"
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
	//delete xd;
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
			//set event
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
	//xd = new XDisplay(width, height);
} //}}}

void Board::loadGame() {
}

void Board::initGame() { //{{{
	string mapfile = "uw.map";
	numPlayer = 3;
	Dice::getInstance(numDice = 2);

	loadMap(mapfile);	
	for(int i = 0; i < numPlayer; i ++) {
		players.push_back(new Player(i, string("") + char('A' + i)));
		cells[0]->addPlayer(players[i]);
		players[i]->setMoney(1500);
		players[i]->setStrategy(0);
		players[i]->setLeftRoll(1);
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
	td->printAll(width, height, cells);
}

void Board::movePlayerTo(const int idPlayer, const int idCell, const bool callEvent) {
	cells[idCell]->movePlayer(players[idPlayer]);
	if(callEvent) cells[idCell]->event(players[idPlayer]);
}

void Board::movePlayerForward(const int idPlayer, const int step) {
	int goal = players[idPlayer]->getCurrentCell()->getID() + step;
	if(goal >= numCell) {
		cout << "Get OSAP of $200" << endl;
		players[idPlayer]->addMoney(200);
	}
	movePlayerTo(idPlayer, (goal + numCell) % numCell);
}

/*****startGame*****/
void Board::startGame() {
	if(savefile.length() > 0) loadGame();
	else initGame();
	bh->setTesting(testing);

	printBoard();
	for(int i = 0; !gameEnd(); i = (i + 1) % numPlayer) 
		if(!players[i]->isBankrupted()) {
			cout << players[i]->getName() << "'s turn" << endl;
			bh->playRound(players[i]);
		}
	cout << "Game Over" << endl;
}

Player* Board::getPlayer(const std::string &name) {
	for(int i = 0; i < numPlayer; i ++)
		if(players[i]->getName() == name) return players[i];
	return NULL;
}
