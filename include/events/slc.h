#ifndef __LOTTERYSLC__
#define __LOTTERYSLC__

#include "event.h"

class Cell;
class SLC : public Event {
	private:
		Cell *block;
	public:
		SLC(Cell &c, Cell *b);
		~SLC();
		void event(Player *p);
};

#endif
