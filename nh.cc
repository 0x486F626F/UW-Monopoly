#include "nh.h"
#include "behavior.h"
#include "board.h"
#include "player.h"
#include <iostream>
using namespace std;

NH::NH(Cell &c) : Event(c) {}
NH::~NH() {}

void NH::event(Player *p) {
	theCell.event(p);
	int r = rand() % 18;
	int m;
	if(r < 1) m = 200;
	else if(r < 3) m = 100;
	else if(r < 6) m = 50;
	else if(r < 12) m = 25;
	else if(r < 15) m = -50;
	else if(r < 17) m = -100;
	else m = -200;
	cout << (m > 0 ? "Win" : "Lose") << " Money $" << (m < 0 ? -m : m) << endl;
	bh->modifyMoney(p, m);
}
