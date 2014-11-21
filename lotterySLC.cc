#include "lotterySLC.h"
#include "board.h"
#include "player.h"
#include <iostream>
using namespace std;

LotterySLC::LotterySLC(Cell &c, const int id) : Event(c), blockID(id) {}
LotterySLC::~LotterySLC() {}

void LotterySLC::event(Player *p) {
	int r = rand() % 24;
	Board *b = Board::getInstance("", 0);
	if(r < 1) {
		cout << "Advance to Collect OSAP" << endl;
		b->movePlayerTo(p->getID(), 0);
	}
	else if(r < 2) {
		cout << "Go to DC Tims Line" << endl;
		p->setBlock(1);
		b->movePlayerTo(p->getID(), blockID);
	}
	else if(r < 6) {
		cout << "Move forward 3" << endl;
		b->movePlayerForward(p->getID(), 3);
	}
	else if(r < 10) {
		cout << "Move forward 2" << endl;
		b->movePlayerForward(p->getID(), 2);
	}
	else if(r < 13) {
		cout << "Move forward 1" << endl;
		b->movePlayerForward(p->getID(), 1);
	}
	else if(r < 17) {
		cout << "Move back 1" << endl;
		b->movePlayerForward(p->getID(), -1);
	}
	else if(r < 21) {
		cout << "Move back 2" << endl;
		b->movePlayerForward(p->getID(), -2);
	}
	else {
		cout << "Move back 3" << endl;
		b->movePlayerForward(p->getID(), -3);
	}
}
