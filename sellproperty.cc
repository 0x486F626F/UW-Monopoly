#include "sellproperty.h"
#include "player.h"
#include <iostream>

using namespace std;

//constructor and destructor
SellProperty::SellProperty(Cell &c) : Event(c) {} 
SellProperty::~SellProperty() {}

void SellProperty::event(Player *p) {
	theCell.event(p);
	if(isBuyable() && p->getMoney() > getCost()) {
		while(1) {
			cout << "Do you want to buy " << theCell.getName() << "? (y/n)" << endl;
			string response;
			cin >> response;
			if(response == "y") {
				p->addMoney(-getCost());
				setOwner(p);
				break;
			}
			else if(response == "n") break;
		}
	}
}
