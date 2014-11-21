#include "collectrent.h"
#include "player.h"
#include "group.h"
#include <iostream>

using namespace std;

CollectRent::CollectRent(Cell &c) : Event(c) {}
CollectRent::~CollectRent() {}

void CollectRent::event(Player *p) {
	theCell.event(p);
	if(isSold() && getOwner()->getID() != p->getID()) {
		int rent = getRent(getLevel());
		if(getGroup()->isMonopoly() && getLevel() == 0) {
			cout << "Monolopy! Double base rent!" << endl;
			rent *= 2;
		}
		cout << "Pay rent " << rent << endl;
		while(1) {
			if(p->getMoney() >= rent) {
				p->addMoney(-rent);
				getOwner()->addMoney(rent);
				break;
			}
			else {
				cout << "Not Enough" << endl;
				//update
				break;
			}
		}
	}
}
