#include "behavior.h"
#include "strategy.h"
#include "player.h"
#include "group.h"
#include "board.h"
#include "dice.h"
#include "cell.h"

#include <iostream>
#include <sstream>
#include <cstdlib>
#ifdef X
#include "xdisplay.h"
#endif

using namespace std;

const int numItem = 1;
const string itemList[] = {"RimCup"};

Behavior::Behavior() {numRimCup = 0;}

Behavior::~Behavior() {}

void	Behavior::cleanInstance() { delete instance; }

Behavior*	Behavior::getInstance() { //{{{
	if(!instance) {
		instance = new Behavior;
		atexit(cleanInstance);
	}
	return instance;
} //}}}

Behavior*	Behavior::instance = NULL;

vector <int>	Behavior::roll(const bool testing) { //{{{
	vector <int> res;
	int n = Dice::getInstance()->getNumDice();
	if(testing) {
		for(int i = 0; i < n; i ++) {
			int t;
			cin >> t;
			res.push_back(t);
		}
	}
	else res = Dice::getInstance()->roll();
	return res;
} //}}}

void	Behavior::setTesting(const bool t) {testing = t;}

void	Behavior::movePlayerTo(Player *p, const int idCell, const bool callEvent) { //{{{
	Board::getInstance()->movePlayerTo(p->getID(), idCell, callEvent);
} //}}}

void	Behavior::movePlayerForward(Player *p, const int step) { //{{{
	Board::getInstance()->movePlayerForward(p->getID(), step);
} //}}}

void	Behavior::modifyMoney(Player *p, const int m) { //{{{
	if(p->getMoney() + m < 0) {
		showmsg("Insufficient fund!");
		lackMoney(-m, p, NULL);
	}
	if(p->isBankrupted()) return;
	p->addMoney(m);
} //}}}

void	Behavior::transferMoney(Player *p1, Player *p2, const int m) { //{{{
	if(p1->getMoney() - m < 0) {
		showmsg("Insufficient fund!");
		lackMoney(m, p1, p2);
	}
	if(p1->isBankrupted()) return;
	p1->addMoney(-m);
	p2->addMoney(m);
} //}}}

void	Behavior::setMoney(Player *p, const int m) {p->setMoney(m);}

int		Behavior::cntProperty(Player *p) {return p->cntProperty();}

void	Behavior::getOSAP(Player *p) { //{{{
	showmsg("Pocketed $200 of OSAP, Good Job!");
	modifyMoney(p, 200);
} //}}}

void	Behavior::block(Player *p) {p->setBlock(1);}

void	Behavior::addBlock(Player *p) {p->setBlock(p->getBlock() + 1);}

void	Behavior::unblock(Player *p) {p->setBlock(0);}

int		Behavior::getBlock(Player *p) {return p->getBlock();}

bool	Behavior::affordable(Player *p, const int m) {return p->getMoney() >= m; }

void	Behavior::buyProperty(Player *p, Cell *c) { //{{{
	c->setOwner(p);
	p->addProperty(c);
} //}}}

void	Behavior::buyImprove(Player *p, const string &s) { //{{{
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		showmsg("You do not own " + s);
		return;
	}
	else {
		if(c->getLevel() >= c->getMaxLevel() || !c->getGroup()->isMonopoly()) {
			cout << c->getLevel() << c->getMaxLevel() << (!c->getGroup()->isMonopoly()) << endl;
			showmsg("This Property cannot be improved");
		}
		else if(!affordable(c->getOwner(), c->getCostImprove())) {
			showmsg("Insufficient fund!");
		}
		else {
			c->getOwner()->addMoney(-c->getCostImprove());
			c->setLevel(c->getLevel() + 1);
		}
	}
} //}}}

void	Behavior::sellImprove(Player *p, const string &s) { //{{{
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		showmsg("You do not own " + s);
		return;
	} 
	else {
		if(c->getLevel() < 1) {
			showmsg("No Improvement to be sold!");
		}
		else {
			c->setLevel(c->getLevel() - 1);
			c->getOwner()->addMoney(c->getCostImprove() / 2);
		}
	}
} //}}}

void	Behavior::transferOwnership(Cell *c, Player *p) { //{{{
	c->getOwner()->removeProperty(c);
	c->setOwner(p);
	p->addProperty(c);
} //}}}

void	Behavior::mortgage(Player *p, const string &s) { //{{{
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		showmsg("You do not own " + s);
		return;
	}
	else {
		if(c->isMortgaged()) {
			showmsg(s + " is already mortgaged!");
		}
		else if(c->getLevel() > 0) {
			showmsg("Improvements on the property, sell before you can mortgage");
		}
		else {
			c->mortgage();
			c->getOwner()->addMoney(c->getCost() / 2);
		}
	}
} //}}}

void	Behavior::unmortgage(Player *p, const string &s) { //{{{
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		showmsg("You do not own " + s);
		return;
	}
	else {
		int cost = c->getCost() * 6 / 10 - c->getPrepaid();
		if(!c->isMortgaged()) {
			showmsg(s + " is not mortgaged!");
		}
		else if(!affordable(c->getOwner(), cost)) {
			showmsg("Insufficient fund!");
		}
		else {
			c->unmortgage();
			c->getOwner()->addMoney(-cost);
			c->setPrepaid(0);
		}
	}
} //}}}

bool	Behavior::strategyBuyProperty(Player *p, Cell *c) {return p->getStrategy()->buyProperty(c, p);}

bool	Behavior::same(Player *p1, Player *p2) {return p1->getID() == p2->getID();}

bool	Behavior::isMonopoly(Group *g) {return g->isMonopoly();}

int		Behavior::numDice() {return Dice::getInstance()->getNumDice();}

int		Behavior::strategyTuition(const int fee, const int rate, Player *p) {return p->getStrategy()->tuition(fee, rate, p);}

int		Behavior::strategyUnblock(Player *p, const int fee, const int itemID) {return p->getStrategy()->unblock(p, fee, itemID); }

int		Behavior::strategyCommand(Player *p) { return p->getStrategy()->command(p); }

int		Behavior::strategyLackMoney(Player *p, const int m) {return p->getStrategy()->lackMoney(p, m);}

string	Behavior::strategyGetPropertyName(Player *p) {return p->getStrategy()->getPropertyName();}

int		Behavior::strategyPrepaid(Player *p, Cell *c) {return p->getStrategy()->prepaid(p, c); }

int		Behavior::getItemID(const string &s) { //{{{
	for(int i = 0; i < numItem; i ++)
		if(itemList[i] == s) return i;
	return -1;
} //}}}

void	Behavior::printAssets(Player *p) {p->printAssets();}

void	Behavior::printBoard() {Board::getInstance()->printBoard();}

void	Behavior::playRound(Player *p) { //{{{
	if(p->getRest() || p->getBlock()) movePlayerForward(p, 0);
	vector <int> d;
	if(!p->getRest() && !p->getBlock()) {
		int decision;
		while(decision = strategyCommand(p)) {
			if(decision == 1) {
				if(p->getLeftRoll() > 0) {
					p->setLeftRoll(p->getLeftRoll() - 1);
					if(p->isComputer()) d = roll(false);
					else d = roll(testing);
#ifdef X
					XDisplay::getInstance()->drawDice(d, 1);
#endif
					int step = 0;
					for(int i = 0; i < d.size(); i ++) {
						cout << d[i] << " ";
						step += d[i];
					}
					showmsg("");
					movePlayerForward(p, step);
					printBoard();
				}
				else showmsg("You have already rolled");
			}
			else if(decision == 2) {
				buyImprove(p, strategyGetPropertyName(p));
				printBoard();
			}
			else if(decision == 3) {
				sellImprove(p, strategyGetPropertyName(p));
				printBoard();
			}
			else if(decision == 4) {
				string name;
				cin >> name;
				mortgage(p, name);
				printBoard();
			}
			else if(decision == 5) {
				string name;
				cin >> name;
				unmortgage(p, name);
				printBoard();
			}
			else if(decision == 6) {
				printAssets(p);
			}
			else if(decision == 7) {
				string name, c1, c2;
				cin >> name >> c1 >> c2;
				if(name == p->getName()) {
					showmsg("You cannot trade with yourself!");
				}
				else {
					Player *p2 = Board::getInstance()->getPlayer(name);
					if(p2) trade(p, p2, c1, c2);
					else showmsg("Player " + name + " does not exist!");
				}
				printBoard();
			}
			else if(decision == 8) {
				string fileName;
				cin >> fileName;
				if(p->getLeftRoll() > 0) showmsg("You cannot save. You have not rolled yet");
				else Board::getInstance()->saveGame(fileName);
			}
		}
	}
#ifdef X
	XDisplay::getInstance()->drawDice(d, 0);
#endif
	p->setLeftRoll(1);
} //}}}

void	Behavior::lackMoney(const int m, Player *p, Player *p2) { //{{{
	while(p->getMoney() < m) {
		cout << "Do not have enough money to pay $" << m << endl;
		showmsg("Trade/ Sell improvement/ Mortgage/ Bankrupt?");
		int decision = strategyLackMoney(p, m);
		if(decision == 1) {
			sellImprove(p, strategyGetPropertyName(p));
		}
		else if(decision == 2) {
			string name;
			cin >> name;
			mortgage(p, name);
		}
		else if(decision == 3) {
			printAssets(p);
		}
		else if(decision == 4) {
			showmsg("Trade: not completed");
		}
		else if(decision == 0) {
			bankrupt(p, p2);
			break;
		}
	}
} //}}}

void	Behavior::bankrupt(Player *p, Player *p2) { //{{{
	Cell *c;
	if(p2) {
		transferMoney(p, p2, p->getMoney());
		showmsg("Assets Transferred to owner");
		while(c = p->getFirstProperty()) {
			transferOwnership(c, p2);
			if(c->isMortgaged()) {
				showmsg("Pay 10\% tax for receiving unmortgaged properties.");
				int cost = c->getCost() / 10;
				if(p2->getMoney() < cost) {
					showmsg("Insufficient fund!");
					lackMoney(cost, p2);
				}
				else p2->addMoney(-cost);
				cost = c->getCost() * 6 / 10;
				cout << p2->getName() + ": Do you want to unmortgage " + c->getName() + " ( value: $" << c->getCost() << string(" )") + " now? (y/n)" << endl;
				int decision = strategyPrepaid(p2, c);
				if(decision == 1) {
					if(p2->getMoney() < cost) {
						showmsg("Insufficient fund!");
						c->setPrepaid(-cost / 6);
					}
					else {
						p2->addMoney(-cost);
						c->unmortgage();
					}
				}
				else c->setPrepaid(-cost / 6);
			}
		}
	}
	else {
		p->setMoney(0);
		while(c = p->getFirstProperty()) {
			c->reset();
			p->removeProperty(c);
		}
	}
	p->setBankrupted(true);
} //}}}

void	Behavior::addItem(Player* p, const string &itemName) {p->addItem(getItemID(itemName));}

bool	Behavior::removeItem(Player* p, const string &itemName) {return p->removeItem(getItemID(itemName));}

int		Behavior::getNumRimCup() { return numRimCup; }

void	Behavior::setNumRimCup(const int num) {numRimCup = num;}

void	Behavior::trade(Player* p1, Player* p2, const string condition1, const string condition2) { //{{{
	int money1, money2;
	istringstream s1(condition1);
	istringstream s2(condition2);
	if(!(s1 >> money1)) money1 = -1;
	if(!(s2 >> money2)) money2 = -1;
	Cell* c1 = p1->findProperty(condition1);
	Cell* c2 = p2->findProperty(condition2);

	if(money1 >= 0 && !affordable(p1, money1)) {
		showmsg( p1->getName() + " has insufficient fund");
		return;
	}
	if(money2 >= 0 && !affordable(p2, money2)) {
		showmsg( p2->getName() + " has insufficient fund");
		return;
	}
	if(money1 < 0 && !c1) {
		showmsg( p1->getName() + " does not own this property " + condition1 );
		return;
	}
	if(money2 < 0 && !c2) {
		showmsg( p2->getName() + " does not own this property " + condition2 );
		return;
	}
	if(money1 < 0 &&(c1->isMortgaged() || !c1->getGroup()->noImprovement())) {
		showmsg( condition1 + " cannot be traded!" );
		return;
	}
	if(money2 < 0 && (c2->isMortgaged() || !c2->getGroup()->noImprovement())) {
		showmsg( condition2 + " cannot be traded!" );
		return;
	}
	if(money1 >= 0 && money2 >= 0) {
		showmsg("Cannot trade money with money");
		return;
	}

	showmsg( p2->getName() + ": Do you accept?(y/n)" );

	int decision;
	if(money1 >= 0 && money2 >= 0) decision = p2->getStrategy()->tradeMM(p1, p2, money1, money2);
	else if(money1 >= 0 && money2 < 0) decision = p2->getStrategy()->tradeMP(p1, p2, money1, c2);
	else if(money1 < 0 && money2 >= 0) decision = p2->getStrategy()->tradePM(p1, p2, c1, money2);
	else if(money1 < 0 && money2 < 0) decision = p2->getStrategy()->tradePP(p1, p2, c1, c2);


	if(decision) {
		showmsg( "Trade completed!");
		if(money1 >= 0) transferMoney(p1, p2, money1);
		else transferOwnership(c1, p2);
		if(money2 >= 0) transferMoney(p2, p1, money2);
		else transferOwnership(c2, p1);
	} 
	else showmsg( "Trade failed!" );
} //}}}

void	Behavior::showmsg(const string &m) {
	cout << m << endl;
	lastmsg = m;
}
