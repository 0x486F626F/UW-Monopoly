#include "computer1.h"
#include "cell.h"

#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;

Computer1::Computer1() {}
Computer1::~Computer1() {}

string Computer1::getPropertyName() {return propertyName;}

int		Computer1::command(Player *p) {
	if(p->getLeftRoll()) return 1;
	else return 0;
}

int		Computer1::lackMoney(Player *p, const int m) {
	return 0;
}

bool	Computer1::buyProperty(Cell *b, Player *p) {
	if(p->getMoney() + 300 >= b->getCost()) return rand() % 4 != 0;
	return 0;
}

int		Computer1::unblock(Player *p, const int fee, const int itemID) {
	return rand() % 3;
}

int		Computer1::tuition(const int fee, const int rate, Player *p) {
	if(fee < p->getMoney() * rate / 100) return 0;
	return 1;
}

int		Computer1::prepaid(Player *p, Cell *c) {
	if(p->getMoney() + 200 > c->getCost() * 6 / 10) return rand() % 5 != 0;
	return 0;
}

bool	Computer1::tradeMM(Player* p1, Player* p2, const int m1, const int m2) {
	if(m1 < m2) return 0;
	return 1;
}

bool	Computer1::tradeMP(Player* p1, Player* p2, const int m1, Cell* c2) {
	if(m1 < c2->getCost()) return 0;
	return rand() % 2;
}

bool	Computer1::tradePM(Player* p1, Player* p2, Cell* c1, const int m2) {
	if(m2 < c1->getCost()) return 0;
	return rand() % 2;
}

bool	Computer1::tradePP(Player* p1, Player* p2, Cell* c1, Cell* c2) {
	return rand() % 4 == 0;
}
