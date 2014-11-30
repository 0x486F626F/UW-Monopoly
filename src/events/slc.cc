#include "slc.h"
#include "behavior.h"
#include <iostream>
#include <cstdlib>
using namespace std;

SLC::SLC(Cell &c, const int i) : Event(c), idBlock(i) {}
SLC::~SLC() {}

void SLC::event(Player *p) {
	theCell.event(p);
	int r = rand() % 24;
	if(r < 1) {
		bh->showmsg( "Teehee, Move to Collect OSAP" );
		bh->getOSAP(p);
		bh->movePlayerTo(p, 0);
	}
	else if(r < 2) {
		bh->showmsg( "Travel to DC Tims Line" );
		bh->block(p);
		bh->movePlayerTo(p, idBlock, 0);
	}
	else if(r < 6) {
		bh->showmsg( "Move forward 3" );
		bh->movePlayerForward(p, 3);
	}
	else if(r < 10) {
		bh->showmsg( "Move forward 2" );
		bh->movePlayerForward(p, 2);
	}
	else if(r < 13) {
		bh->showmsg( "Move forward 1" );
		bh->movePlayerForward(p, 1);
	}
	else if(r < 17) {
		bh->showmsg( "Move back 1" );
		bh->movePlayerForward(p, -1);
	}
	else if(r < 21) {
		bh->showmsg( "Move back 2" );
		bh->movePlayerForward(p, -2);
	}
	else {
		bh->showmsg( "Move back 3" );
		bh->movePlayerForward(p, -3);
	}
}
