#include "modifymoney.h"
#include "behavior.h"
#include <iostream>
using namespace std;

ModifyMoney::ModifyMoney(Cell &c, const int m) : Event(c), money(m) {}
ModifyMoney::~ModifyMoney() {}

void ModifyMoney::event(Player *p) {
	theCell.event(p);
	cout << (money > 0 ? "Win" : "Lose") << " $" << (money < 0 ? -money : money) << endl;
	bh->modifyMoney(p, money);
}
