#include "rollrent.h"
#include "behavior.h"
#include <iostream>
#include <vector>
using namespace std;

RollRent::RollRent(Cell &c) : Event(c) {}
RollRent::~RollRent() {}

void RollRent::event(Player *p) {
	theCell.event(p);
	if(isSold() && !bh->same(getOwner(), p) && !isMortgaged()) {
		int multi = 4;
		if(bh->isMonopoly(getGroup())) multi = 10;
		cout << "Rent is " << multi << "*sum of dice" << endl;
		vector <int> d = bh->roll();
		int tot = 0;
		for(int i = 0; i < bh->numDice(); i ++)
			tot += d[i];
		cout << "Pay rent $" << tot * multi << endl;
		bh->transferMoney(p, getOwner(), multi * tot);
	}
}
