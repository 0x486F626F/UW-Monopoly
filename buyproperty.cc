#include "buyproperty.h"
#include "behavior.h"
#include "player.h"
#include "strategy.h"
#include <iostream>

using namespace std;

//constructor and destructor
BuyProperty::BuyProperty(Cell &c) : Event(c) {} 
BuyProperty::~BuyProperty() {}

void BuyProperty::event(Player *p) {
	theCell.event(p);
	if(canBuy() && bh->affordable(p, getCost())) {
		cout << "Do you want to buy " << theCell.getName() << "? (y/n)" << endl;
		if(p->getStrategy()->buyProperty(this, p)) {
			bh->buyProperty(p, this);	
			bh->modifyMoney(p, -getCost());
		}
	}
}
