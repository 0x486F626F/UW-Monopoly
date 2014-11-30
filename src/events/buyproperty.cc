#include "buyproperty.h"
#include "behavior.h"
#include <iostream>

using namespace std;

//constructor and destructor
BuyProperty::BuyProperty(Cell &c) : Event(c) {} 
BuyProperty::~BuyProperty() {}

void BuyProperty::event(Player *p) {
	theCell.event(p);
	if(canBuy() && bh->affordable(p, getCost())) {
		bh->showmsg( "Do you want to buy " + theCell.getName() + "? (y/n)" );
		if(bh->strategyBuyProperty(p, this)) {
			bh->buyProperty(p, this);	
			bh->modifyMoney(p, -getCost());
			bh->showmsg( "Nice work! You acquired " + getName() );
		}
		else {
		   bh->showmsg( "Maybe Next time :) " );
		   bh->showmsg( getName() + " is still offered in the open market");
		}
	}
}
