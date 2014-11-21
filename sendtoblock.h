#ifndef __SENDTOBLOCK_H__
#define __SENDTOBLOCK_H__

#include <vector>
#include "event.h"

class Cell;

class SendToBlock : public Event{
	private:
		int goal;
		std::vector<Cell*> &cells;
	public:
		SendToBlock(Cell &c, int id, std::vector<Cell*> &cv);
		~SendToBlock();

		void event(Player *p);
};

#endif
