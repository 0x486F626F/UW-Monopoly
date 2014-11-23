#include "rollrent.h"
#include "behavior.h"
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
		vector <int> d = bh->roll();
		int tot = 0;
		for(int i = 0; i < Dice::getInstance()->getNumDice(); i ++)
			tot += d[i];
		cout << "Pay rent $" << tot * multi << endl;
		bh->modifyMoney(p, -multi * tot);
		bh->modifyMoney(getOwner(), multi * tot);
	}
}
