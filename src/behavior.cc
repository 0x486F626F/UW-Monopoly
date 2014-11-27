#include "behavior.h"
#include "strategy.h"
#include "player.h"
#include "group.h"
#include "board.h"
#include "dice.h"
#include "cell.h"

#include <iostream>
#include <cstdlib>

using namespace std;

Behavior::Behavior() {}
Behavior::~Behavior() {}
void	Behavior::cleanInstance() { delete instance; }
Behavior*	Behavior::getInstance() {
	if(!instance) {
		instance = new Behavior;
		atexit(cleanInstance);
	}
	return instance;
}
Behavior*	Behavior::instance = NULL;

vector <int>	Behavior::roll(const bool testing) {
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
}

void	Behavior::setTesting(const bool t) {testing = t;}
void	Behavior::movePlayerTo(Player *p, const int idCell, const bool callEvent) {
	Board::getInstance()->movePlayerTo(p->getID(), idCell, callEvent);
}
void	Behavior::movePlayerForward(Player *p, const int step) {
	Board::getInstance()->movePlayerForward(p->getID(), step);
}

void	Behavior::modifyMoney(Player *p, const int m) {
	if(p->getMoney() + m < 0) {
		cout << "Money is not enough!" << endl;
		lackMoney(-m, p, NULL);
	}
	if(p->isBankrupted()) return;
	p->addMoney(m);
}

void	Behavior::transferMoney(Player *p1, Player *p2, const int m) {
	if(p1->getMoney() - m < 0) {
		cout << "Money is not enough!" << endl;
		lackMoney(m, p1, p2);
	}
	if(p1->isBankrupted()) return;
	p1->addMoney(-m);
	p2->addMoney(m);
}
void	Behavior::setMoney(Player *p, const int m) {p->setMoney(m);}
int		Behavior::cntProperty(Player *p) {return p->cntProperty();}
void	Behavior::getOSAP(Player *p) {
	cout << "Get OSAP of $200" <<endl;
	modifyMoney(p, 200);
}
void	Behavior::block(Player *p) {p->setBlock(1);}
void	Behavior::addBlock(Player *p) {p->setBlock(p->getBlock() + 1);}
void	Behavior::unblock(Player *p) {p->setBlock(0);}
int		Behavior::getBlock(Player *p) {return p->getBlock();}
bool	Behavior::affordable(Player *p, const int m) {return p->getMoney() >= m; }
//void	Behavior::bankrupt(Player *p) {p->backrupt();}

void	Behavior::buyProperty(Player *p, Cell *c) {
	c->setOwner(p);
	p->addProperty(c);
}

void	Behavior::buyImprove(Player *p, const string &s) {
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		cout << p->getName() << " does not have " << s << endl;
		return;
	}
	else {
		if(c->getLevel() >= c->getMaxLevel() || !c->getGroup()->isMonopoly()) {
			cout << c->getLevel() << c->getMaxLevel() << (!c->getGroup()->isMonopoly()) << endl;
			cout << "This Property cannot be improved" << endl;
		}
		else if(!affordable(c->getOwner(), c->getCostImprove())) {
			cout << "Money is not enough!" << endl;
		}
		else {
			c->getOwner()->addMoney(-c->getCostImprove());
			c->setLevel(c->getLevel() + 1);
		}
	}
}

void	Behavior::sellImprove(Player *p, const string &s) {
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		cout << p->getName() << " does not have " << s << endl;
		return;
	} 
	else {
		if(c->getLevel() < 1) {
			cout << "No Improvement can be sold!" << endl;
		}
		else {
			c->setLevel(c->getLevel() - 1);
			c->getOwner()->addMoney(c->getCostImprove() / 2);
		}
	}
}

void	Behavior::transferOwnership(Cell *c, Player *p) {
	c->getOwner()->removeProperty(c);
	c->setOwner(p);
	p->addProperty(c);
}

void	Behavior::mortgage(Player *p, const string &s) {
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		cout << p->getName() << " does not have " << s << endl;
		return;
	}
	else {
		if(c->isMortgaged()) {
			cout << s << " is already mortgaged!" << endl;
		}
		else if(c->getLevel() > 0) {
			cout << "Have improvements on the property! Cannot be mortgaged!" << endl;
		}
		else {
			c->mortgage();
			c->getOwner()->addMoney(c->getCost() / 2);
		}
	}
}

void	Behavior::unmortgage(Player *p, const string &s) {
	Cell *c = p->findProperty(s);
	if(c == NULL) {
		cout << p->getName() << " does not have " << s << endl;
		return;
	}
	else {
		int cost = c->getCost() * 6 / 10 - c->getPrepaid();
		cout << "Prepaid	" << c->getPrepaid();
		if(!affordable(c->getOwner(), cost)) {
			cout << "Money is not enough!" << endl;
		}
		else {
			c->unmortgage();
			c->getOwner()->addMoney(-cost);
			c->setPrepaid(0);
		}
	}
}

void	Behavior::printMsg(const string &s) {cout << s << endl;}

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

int		Behavior::getItemID(const string &s) {
	//search ID
	return 0;
}

void	Behavior::printAssets(Player *p) {p->printAssets();}

void	Behavior::printBoard() {Board::getInstance()->printBoard();}

void	Behavior::playRound(Player *p) {
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
				else cout << "You have rolled" << endl;
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
			printBoard();
		}
	}
	else {
		movePlayerForward(p, 0);
		printBoard();
	}
	p->setLeftRoll(1);
}

void	Behavior::lackMoney(const int m, Player *p, Player *p2) {
	while(p->getMoney() < m) {
		cout << "Do not have enough money to pay $" << m << endl;
		cout << "Trade/Sell improvement/Mortgage/Bankrupt?" << endl;
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
}

void	Behavior::bankrupt(Player *p, Player *p2) {
	p->setBankrupted(true);
	Cell *c;
	if(p2) {
		transferMoney(p, p2, p->getMoney());
		cout << "Money Transfered!" << endl;
		while(c = p->getFirstProperty()) {
			transferOwnership(c, p2);
			if(c->isMortgaged()) {
				cout << p2->getName() << ": Do you want to pay 10\% now? (y/n)" << endl;
				int decision = strategyPrepaid(p2, c);
				int cost = c->getCost() / 10;
				c->setPrepaid(-cost);
				if(decision == 1) {
					if(p2->getMoney() < cost) {
						cout << "Money is not enough!" << endl;
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
}
