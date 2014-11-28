#include "collectrent.h"
#include "behavior.h"
#include "player.h"
#include <iostream>

using namespace std;

CollectRent::CollectRent(Cell &c) : Event(c) {}
CollectRent::~CollectRent() {}

void CollectRent::event(Player *p) {
	theCell.event(p);
	//check if the the property is owned and Player p is not the owner
	if(isSold() && !bh->same(getOwner(), p) && !isMortgaged()) {
		//get current rent level
		int rent = getRent(getLevel());
		//check if the group is monopolized
		if(bh->isMonopoly(getGroup()) && getLevel() == 0) {
			cout << "Monolopy Here!!! Pay DOUBLE Rent" << endl;
			rent *= 2;
		}
		cout << getOwner()->getName() <<" owns this property. Pay rent $" << rent << endl;
		bh->transferMoney(p, getOwner(), rent);
	}
}
