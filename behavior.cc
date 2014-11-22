#include "behavior.h"
#include "player.h"
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

vector <int>	Behavior::roll() {return Dice::getInstance()->roll();}
vector <int>	Behavior::roll(vector <int> v) {return v;}

void	Behavior::movePlayerTo(Player *p, Cell *c) {
	Board::getInstance()->movePlayerTo(p->getID(), c->getID());
}
void	Behavior::movePlayerForward(Player *p, const int step) {
	Board::getInstance()->movePlayerForward(p->getID(), step);
}

void	Behavior::modifyMoney(Player *p, const int m) {
	if(p->getMoney() + m < 0) {
		cout << "Money is not enough!" << endl;
		//strategy;
	} 
	else p->addMoney(m);
}
void	Behavior::setMoney(Player *p, const int m) {p->setMoney(m);}
void	Behavior::block(Player *p) {p->setBlock(1);}
void	Behavior::addBlock(Player *p) {p->setBlock(p->getBlock() + 1);}
void	Behavior::unblock(Player *p) {p->setBlock(0);}
//void	Behavior::bankrupt(Player *p) {p->backrupt();}

void	Behavior::buyProperty(Player *p, Cell *c) {
	c->setOwner(p);
	p->addProperty(c);
}

void	Behavior::buyImprove(Cell *c) {
	if(c->getLevel() >= c->getMaxLevel()) {
		cout << "This Property cannot be improved" << endl;
	}
	else if(c->getOwner()->getMoney() < c->getCostImprove()) {
		cout << "Money is not enough!" << endl;
	}
	else {
		c->getOwner()->addMoney(-c->getCostImprove());
		c->setLevel(c->getLevel() + 1);
	}
}

void	Behavior::sellImprove(Cell *c) {
	if(c->getLevel() < 1) {
		cout << "No Improvement can be sold!" << endl;
	}
	else {
		c->setLevel(c->getLevel() - 1);
		c->getOwner()->addMoney(c->getCostImprove() / 2);
	}
}

void	mortgage(Cell *c) {
	c->mortgage();
	c->getOwner()->addMoney(c->getCost() / 2);
}

void	unmortgage(Cell *c) {
	int cost = c->getCost() * 6 / 10;
	if(cost > c->getOwner()->getMoney()) {
		cout << "Money is not enough!" << endl;
	}
	else {
		c->unmortgage();
		c->getOwner()->addMoney(-cost);
	}
}
