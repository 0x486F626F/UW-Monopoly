#include "timline.h"
#include "behavior.h"
#include "strategy.h"
#include "player.h"
#include "dice.h"

#include <iostream>
#include <vector>
using namespace std;

//constructor and destructor
TimLine::TimLine(Cell &c, const int f, const string i) : Event(c), fee(f), itemname(i) {}
TimLine::~TimLine() {}

void TimLine::event(Player *p) {
	theCell.event(p);

	if(bh->getBlock(p) > 0) {
		cout << "Sorry, You are blocked in " << getName() << endl;
		while(1) {
			cout << "Do you want to roll dice / pay money $" << fee << " /use " << itemname << "? (r/p/i)" << endl;
			int itemID = bh->getItemID(itemname);
			int decision = bh->strategyUnblock(p, fee, itemID);
			if(decision == 0) {
				cout << "Roll dice ";
				vector <int> t = bh->roll();
				cout << t[0] << " " << t[1] << endl;
				//check if the two rolled result is same
				if(t[0] == t[1]) {
					cout << "So lucky, You are free!" << endl;
					bh->unblock(p);
				}
				else {
				   cout << "Not so easy, You are still trapped here" << endl;
				   bh->addBlock(p);
				}
				//if a player got trapped for the third rounds, must pay to leave
				if(p->getBlock() > 3) {
					if(!bh->affordable(p, fee)) {
						cout << "You have insufficient fund!" << endl;
						bh->lackMoney(fee, p);
					}
					cout << "Pay $" << fee << endl << "You are out at last" << endl;
					bh->modifyMoney(p, -fee);
					bh->unblock(p);
					int sum = 0;
					for(int i = 0; i < bh->numDice(); i ++)
						sum += t[i];
					bh->movePlayerForward(p, sum);
				}
				break;
			}
			else if(decision == 1) {
				if(bh->affordable(p, fee)) {
					cout << "Pay $" << fee << endl << "Rich dude, LEAVE" << endl;
					bh->modifyMoney(p, -fee);
					bh->unblock(p);
					break;
				}
				else cout << "You have insufficient fund!" << endl;
			}
			else if(decision == 2) {
				if(bh->removeItem(p, "RimCup")) {
				   cout << "You lose a RimCup, Unblocked" << endl;
					bh->setNumRimCup(bh->getNumRimCup() - 1);
					bh->unblock(p);
					break;
				}
				else cout << "No RimCup detected, try again" << endl;
			}
		}
	}
}
