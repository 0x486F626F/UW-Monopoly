#ifndef __SENDTOBLOCK_H__
#define __SENDTOBLOCK_H__

#include "event.h"

class Cell;

class SendToBlock : public Event{
	private:
		Cell *block;
	public:
		SendToBlock(Cell &c, Cell *b);
		~SendToBlock();

		void event(Player *p);
};

#endif
