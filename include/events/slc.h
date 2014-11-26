#ifndef __LOTTERYSLC__
#define __LOTTERYSLC__

#include "event.h"

class Cell;
class SLC : public Event {
	private:
		int idBlock;
	public:
		SLC(Cell &c, const int i);
		~SLC();
		void event(Player *p);
};

#endif
