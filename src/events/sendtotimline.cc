#include "sendtotimline.h"
#include "behavior.h"
#include <iostream>

using namespace std;

SendToTimLine::SendToTimLine(Cell &c, const int i) : Event(c), idBlock(i) {}
SendToTimLine::~SendToTimLine() {}

void SendToTimLine::event(Player *p) {
	theCell.event(p);
	bh->showmsg( "Oooooops, you are sent to the DC Tims Line" );
	bh->block(p);
	bh->movePlayerTo(p, idBlock, 0);
}
