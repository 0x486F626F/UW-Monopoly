#include "tuition.h"
#include "behavior.h"
#include <iostream>
using namespace std;

Tuition::Tuition(Cell &c) : Event(c) {}
Tuition::~Tuition() {}

void	Tuition::event(Player *p) {
	theCell.event(p);
	cout << "Pay tuition! $300 or 10\% of total property? (a/b)" << endl;
	int m = 300;
	if(bh->strategyTuition(300, 10, p) == 1) m = bh->cntProperty(p) / 10;
	bh->modifyMoney(p, -m);
}
