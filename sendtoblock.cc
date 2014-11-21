#include "sendtoblock.h"
#include "player.h"
#include <iostream>

using namespace std;

SendToBlock::SendToBlock(Cell &c, int id, vector <Cell*> &vc) : Event(c), goal(id), cells(vc) {}
SendToBlock::~SendToBlock() {}

void SendToBlock::event(Player *p) {
	theCell.event(p);
	cout << "You are sent to " << getName() << endl;
	p->setBlock(1);
	cells[goal]->movePlayer(p);
}
