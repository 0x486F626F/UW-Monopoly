#include "sendtotimline.h"
#include "behavior.h"
#include <iostream>

using namespace std;

SendToTimLine::SendToTimLine(Cell &c, Cell *b) : Event(c), block(b) {}
SendToTimLine::~SendToTimLine() {}

void SendToTimLine::event(Player *p) {
	theCell.event(p);
	cout << "You are sent to " << getName() << endl;
	bh->block(p);
	bh->movePlayerTo(p, block, 0);
}
