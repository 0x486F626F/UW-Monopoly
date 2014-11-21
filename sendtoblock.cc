#include "sendtoblock.h"
#include "player.h"
#include <iostream>

using namespace std;

SendToBlock::SendToBlock(Cell &c, Cell *b) : Event(c), block(b) {}
SendToBlock::~SendToBlock() {}

void SendToBlock::event(Player *p) {
	theCell.event(p);
	cout << "You are sent to " << getName() << endl;
	p->setBlock(1);
	block->movePlayer(p);
}
