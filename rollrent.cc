#include "rollrent.h"
#include "player.h"
#include "group.h"
#include "dice.h"
#include <iostream>
#include <vector>
using namespace std;

RollRent::RollRent(Cell &c) : Event(c) {}
RollRent::~RollRent() {}

void RollRent::event(Player *p) {
	theCell.event(p);
	if(isSold() && getOwner()->getID() != p->getID()) {
		int multi = 4;
		if(getGroup()->isMonopoly()) multi = 10;
		cout << "Rent is " << multi << "*sum of dice" << endl;
		int d = p->roll(0);
		cout << "Pay rent $" << d * multi << endl;
		p->addMoney(-multi * d);
		getOwner()->addMoney(multi * d);
	}
}
