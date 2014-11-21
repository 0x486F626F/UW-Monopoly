#include "board.h"
#include "cell.h"
#include "group.h"
#include "facility.h"
#include "property.h"
#include "textdisplay.h"
//#include "xdisplay.h"
#include "player.h"

#include "strategy.h"
#include "human.h"

#include "sellproperty.h"
#include "collectrent.h"
#include "sendtoblock.h"
#include "blocktimline.h"
#include "lotterySLC.h"
#include "lotteryNH.h"
#include "modifymoney.h"
#include "rollrent.h"

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
			Property *tp = new Property(i, name);	
			p = tp;
			bool found = false;
			for(vector <Group*>::iterator i = groups.begin(); i != groups.end(); i ++)
				if((*i)->getName() == group) { 
					(*i)->addProperty(tp); 
					found = true;
				}
			if(!found) {
				groups.push_back(new Group(numGroup ++, group));
				(*(groups.end() - 1))->addProperty(tp);
			}
		}

		stream >> cost;
		if(cost) {
			stream >> cost >> rent;
			p->setCost(cost);
			p->addRent(rent);
			p = new SellProperty(*p);
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
				cout << p->getID() << endl;
				p = new BlockTimline(*p, fee, itemname);
			}
			else if(eventname == "SendToBlock") {
				int id;
				stream >> id;
				p = new SendToBlock(*p, cells[id]);
			}
			else if(eventname == "SLC") {
				int id;
				stream >> id;
				p = new LotterySLC(*p, id);
			}
			else if(eventname == "NH") {
				p = new LotteryNH(*p);
			}
			else if(eventname == "ModifyMoney") {
				int m;
				stream >> m;
				p = new ModifyMoney(*p, m);
			}
			else if(eventname == "RollRent") {
				p = new RollRent(*p);
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

	loadMap(mapfile);	
	for(int i = 0; i < numPlayer; i ++) {
		players.push_back(new Player(i, string("") + char('A' + i)));
		cells[0]->addPlayer(players[i]);
		players[i]->setMoney(1500);
		players[i]->setStrategy(0);
		players[i]->setLeftRoll(1);
	}
} //}}}

bool Board::gameEnd() { return false; }

/*****printBoard*****/
void Board::printBoard() {
	td->printAll(width, height, cells);
}

void Board::movePlayerTo(const int idPlayer, const int idCell) {
	cells[idCell]->movePlayer(players[idPlayer]);
	cells[idCell]->event(players[idPlayer]);
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

	printBoard();
	printPlayerInfo();
	for(int i = 0; !gameEnd(); i = (i + 1) % numPlayer) {
		cout << players[i]->getName() << "'s turn" << endl;
		if(!players[i]->getRest() && !players[i]->getBlock()) {
			int decision;
			while(decision = players[i]->getStrategy()->command(players[i])) {
				if(decision == 1) {
					if(players[i]->getLeftRoll() > 0) {
						players[i]->setLeftRoll(players[i]->getLeftRoll() - 1);
						int step = players[i]->roll(testing);
						movePlayerForward(i, step);
					}
					else cout << "You have rolled" << endl;
				}
				printBoard();
			}
		}
		else {
			cells[players[i]->getCurrentCell()->getID()]->event(players[i]);
			printBoard();
		}
		printPlayerInfo();
		players[i]->setLeftRoll(1);
	}

}

void Board::printPlayerInfo() {
	for(int i = 0; i < numPlayer; i ++) {
		players[i]->printInfo();	
	}
}
