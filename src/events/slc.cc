#include "slc.h"
#include "behavior.h"
#include <iostream>
#include <cstdlib>
using namespace std;

SLC::SLC(Cell &c, Cell* b) : Event(c), block(b) {}
SLC::~SLC() {}

void SLC::event(Player *p) {
	theCell.event(p);
	int r = rand() % 24;
	if(r < 1) {
		cout << "Advance to Collect OSAP" << endl;
		bh->getOSAP(p);
		bh->movePlayerTo(p, 0);
	}
	else if(r < 2) {
		cout << "Go to DC Tims Line" << endl;
		bh->block(p);
		bh->movePlayerTo(p, block, 0);
	}
	else if(r < 6) {
		cout << "Move forward 3" << endl;
		bh->movePlayerForward(p, 3);
	}
	else if(r < 10) {
		cout << "Move forward 2" << endl;
		bh->movePlayerForward(p, 2);
	}
	else if(r < 13) {
		cout << "Move forward 1" << endl;
		bh->movePlayerForward(p, 1);
	}
	else if(r < 17) {
		cout << "Move back 1" << endl;
		bh->movePlayerForward(p, -1);
	}
	else if(r < 21) {
		cout << "Move back 2" << endl;
		bh->movePlayerForward(p, -2);
	}
	else {
		cout << "Move back 3" << endl;
		bh->movePlayerForward(p, -3);
	}
}
