#include "rollrimcup.h"
#include "behavior.h"
#include <cstdlib>
#include <iostream>

using namespace std;

RollRimCup::RollRimCup(Cell &c) : Event(c) {}
RollRimCup::~RollRimCup() {}

void RollRimCup::event(Player* p) {
	if(bh->getNumRimCup() < 4) {
		int r = rand() % 100;
		if(r < 50) {
			cout << "Cong! Win RimCup!" << endl;
			bh->setNumRimCup(bh->getNumRimCup() + 1);
			bh->addItem(p, "RimCup");
		}
		else theCell.event(p);
	}
}
