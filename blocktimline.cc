#include "blocktimline.h"
#include "strategy.h"
#include "player.h"
#include "dice.h"

#include <iostream>
#include <vector>
using namespace std;

BlockTimline::BlockTimline(Cell &c, const int f, const string i) : Event(c), fee(f), itemname(i) {}
BlockTimline::~BlockTimline() {}

void BlockTimline::event(Player *p) {
	theCell.event(p);

	if(p->getBlock() > 3) {
		cout << "Pay $" << fee << endl << "Unblock!" << endl;
		p->addMoney(-fee);
		p->setBlock(0);
	}
	else if(p->getBlock() > 0) {
		cout << "You are block in " << getName() << endl;
		cout << "Do you want to roll dice / pay $" << fee << " use " << itemname << "? (r/p/i)" << endl;
		int decision = p->getStrategy()->unblock(p, fee, itemname);
		if(decision == 0) {
			cout << "Roll dice ";
			vector <int> t = p->getDice()->roll();
			cout << t[0] << " " << t[1] << endl;
			if(t[0] == t[1]) {
				cout << "Unblock!" << endl;
				p->setBlock(0);
			}
			else p->setBlock(p->getBlock() + 1);
		}
		else if(decision == 1) {
			cout << "Pay $" << fee << endl << "Unblock!" << endl;
			p->addMoney(-fee);
			p->setBlock(0);
		}
		else if(decision == 2) {
			cout << "Use " << itemname << endl << "Unblock!" << endl;
			p->setBlock(0);
			//update use item
		}
	}
}
