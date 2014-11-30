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
		cout << "Insufficient fund!" << endl;
		lackMoney(-m, p, NULL);
	}
	if(p->isBankrupted()) return;
	p->addMoney(m);
} //}}}

void	Behavior::transferMoney(Player *p1, Player *p2, const int m) { //{{{
	if(p1->getMoney() - m < 0) {
		cout << "Insufficient fund!" << endl;
		lackMoney(m, p1, p2);
	}
	if(p1->isBankrupted()) return;
	p1->addMoney(-m);
	p2->addMoney(m);
} //}}}

void	Behavior::setMoney(Player *p, const int m) {p->setMoney(m);}

int		Behavior::cntProperty(Player *p) {return p->cntProperty();}

void	Behavior::getOSAP(Player *p) { //{{{
	cout << "Pocketed $200 of OSAP, Good Job!" <<endl;
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
		cout << "You do not own " << s << endl;
		return;
	}
	else {
		if(c->getLevel() >= c->getMaxLevel() || !c->getGroup()->isMonopoly()) {
			cout << c->getLevel() << c->getMaxLevel() << (!c->getGroup()->isMonopoly()) << endl;
			cout << "This Property cannot be improved" << endl;
		}
		else if(!affordable(c->getOwner(), c->getCostImprove())) {
			cout << "Insufficient fund!" << endl;
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
		cout << "You do not own " << s << endl;
		return;
	} 
	else {
		if(c->getLevel() < 1) {
			cout << "No Improvement to be sold!" << endl;
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
		cout << "You do not own " << s << endl;
		return;
	}
	else {
		if(c->isMortgaged()) {
			cout << s << " is already mortgaged!" << endl;
		}
		else if(c->getLevel() > 0) {
			cout << "Improvements on the property, sell before you can mortgage" << endl;
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
		cout << "You do not own " << s << endl;
		return;
	}
	else {
		int cost = c->getCost() * 6 / 10 - c->getPrepaid();
		if(!c->isMortgaged()) {
			cout << s << " is not mortgaged!" << endl;
		}
		else if(!affordable(c->getOwner(), cost)) {
			cout << "Insufficient fund!" << endl;
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

int		Behavior::strategyGetChar(Player *p) {return p->getStrategy()->getChar();}

int		Behavior::getItemID(const string &s) { //{{{
	for(int i = 0; i < numItem; i ++)
		if(itemList[i] == s) return i;
	return -1;
} //}}}

void	Behavior::printAssets(Player *p) {p->printAssets();}

void	Behavior::printBoard() {Board::getInstance()->printBoard();}

void	Behavior::playRound(Player *p) { //{{{
	if(!p->getRest() && !p->getBlock()) {
		int decision;
		while(decision = strategyCommand(p)) {
			if(decision == 1) {
				if(p->getLeftRoll() > 0) {
					p->setLeftRoll(p->getLeftRoll() - 1);
					vector <int> d = roll(testing);
					int step = 0;
					for(int i = 0; i < d.size(); i ++)
						step += d[i];
					movePlayerForward(p, step);
				}
				else cout << "You have already rolled" << endl;
			}
			else if(decision == 2) {
				buyImprove(p, strategyGetPropertyName(p));
			}
			else if(decision == 3) {
				sellImprove(p, strategyGetPropertyName(p));
			}
			else if(decision == 4) {
				string name;
				cin >> name;
				mortgage(p, name);
			}
			else if(decision == 5) {
				string name;
				cin >> name;
				unmortgage(p, name);
			}
			else if(decision == 6) {
				printAssets(p);
			}
			else if(decision == 7) {
				string name, c1, c2;
				cin >> name >> c1 >> c2;
				if(name == p->getName()) {
					cout << "You cannot trade with yourself!" << endl;
				}
				else {
					Player *p2 = Board::getInstance()->getPlayer(name);
					if(p2) trade(p, p2, c1, c2);
					else cout << "Player " + name + " does not exist!" << endl;
				}
			}
			else if(decision == 8) {
				string fileName;
				cin >> fileName;
				if(p->getLeftRoll() > 0) cout << "You cannot save. You have not rolled yet" << endl;
				else Board::getInstance()->saveGame(fileName);
			}
			printBoard();
		}
	}
	else {
		movePlayerForward(p, 0);
		printBoard();
	}
	p->setLeftRoll(1);
} //}}}

void	Behavior::lackMoney(const int m, Player *p, Player *p2) { //{{{
	while(p->getMoney() < m) {
		cout << "Do not have enough money to pay $" << m << endl;
		cout << "Trade/ Sell improvement/ Mortgage/ Bankrupt?" << endl;
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
			cout << "Trade: not completed" << endl;
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
		cout << "Money Transfered!" << endl;
		while(c = p->getFirstProperty()) {
			transferOwnership(c, p2);
			if(c->isMortgaged()) {
				cout << p2->getName() << ": Do you want to pay the 10\% interest now? (y/n)" << endl;
				int decision = strategyPrepaid(p2, c);
				int cost = c->getCost() / 10;
				c->setPrepaid(-cost);
				if(decision == 1) {
					if(p2->getMoney() < cost) {
						cout << "Insufficient fund!" << endl;
					}
					else {
						p2->addMoney(-cost);
						c->setPrepaid(cost);
					}
				}
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
		cout << p1->getName() << " does not have enough money!" << endl;
		return;
	}
	if(money2 >= 0 && !affordable(p2, money2)) {
		cout << p2->getName() << " does not have enough money!" << endl;
		return;
	}
	if(money1 < 0 && !c1) {
		cout << p1->getName() << " does not own property " << condition1 << endl;
		return;
	}
	if(money2 < 0 && !c2) {
		cout << p2->getName() << " does not own property " << condition2 << endl;
		return;
	}
	if(money1 < 0 &&(c1->isMortgaged() || !c1->getGroup()->noImprovement())) {
		cout << condition1 << " cannot be traded!" << endl;
		return;
	}
	if(money2 < 0 && (c2->isMortgaged() || !c2->getGroup()->noImprovement())) {
		cout << condition2 << " cannot be traded!" << endl;
		return;
	}

	cout << p2->getName() << ": Do you accept?(y/n)" << endl;

	int decision;
	if(money1 >= 0 && money2 >= 0) decision = p2->getStrategy()->tradeMM(p1, p2, money1, money2);
	else if(money1 >= 0 && money2 < 0) decision = p2->getStrategy()->tradeMP(p1, p2, money1, c2);
	else if(money1 < 0 && money2 >= 0) decision = p2->getStrategy()->tradePM(p1, p2, c1, money2);
	else if(money1 < 0 && money2 < 0) decision = p2->getStrategy()->tradePP(p1, p2, c1, c2);


	if(decision) {
		cout << p2->getName() << " accepted!" << endl;
		if(money1 >= 0) transferMoney(p1, p2, money1);
		else transferOwnership(c1, p2);
		if(money2 >= 0) transferMoney(p2, p1, money2);
		else transferOwnership(c2, p1);
	} 
	else cout << p2->getName() << " declined!" << endl;
} //}}}
