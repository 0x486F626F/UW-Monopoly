#ifndef __SENDTOBLOCK_H__
#define __SENDTOBLOCK_H__

#include "event.h"

class Cell;

class SendToTimLine : public Event{
	private:
		int idBlock;
	public:
		SendToTimLine(Cell &c, const int i);
		~SendToTimLine();

		void event(Player *p);
};

#endif
