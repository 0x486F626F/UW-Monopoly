#ifndef __SENDTOBLOCK_H__
#define __SENDTOBLOCK_H__

#include "event.h"

class Cell;

class SendToTimLine : public Event{
	private:
		Cell *block;
	public:
		SendToTimLine(Cell &c, Cell *b);
		~SendToTimLine();

		void event(Player *p);
};

#endif
