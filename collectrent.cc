#include "collectrent.h"
#include "player.h"
#include <iostream>

using namespace std;

CollectRent::CollectRent(Cell &c) : Event(c) {}
CollectRent::~CollectRent() {}

void CollectRent::event(Player *p) {
	theCell.event(p);
	if(isSold() && getOwner()->getID() != p->getID()) {
		int rent = getRent(getLevel());
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
