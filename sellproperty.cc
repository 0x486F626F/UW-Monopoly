#include "sellproperty.h"
#include "player.h"
#include "strategy.h"
#include <iostream>

using namespace std;

//constructor and destructor
SellProperty::SellProperty(Cell &c) : Event(c) {} 
SellProperty::~SellProperty() {}

void SellProperty::event(Player *p) {
	theCell.event(p);
	if(canBuy() && p->getMoney() > getCost()) {
		cout << "Do you want to buy " << theCell.getName() << "? (y/n)" << endl;
		if(p->getStrategy()->buyProperty(this, p)) {
			p->addMoney(-getCost());
			setOwner(p);
		}
	}
}
