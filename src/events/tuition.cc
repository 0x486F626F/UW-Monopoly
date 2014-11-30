#include "tuition.h"
#include "behavior.h"
#include <iostream>
using namespace std;

Tuition::Tuition(Cell &c) : Event(c) {}
Tuition::~Tuition() {}

void	Tuition::event(Player *p) {
	theCell.event(p);
	bh->showmsg("New term starting, Pay tuition! $300 or 10\% of total net worth? (a/b)");
	int m = 300;
	if(bh->strategyTuition(300, 10, p) == 1) m = bh->cntProperty(p) / 10;
	bh->modifyMoney(p, -m);
	if (p->isBankrupted() == false) cout << "You payed $" << m << endl;
}
