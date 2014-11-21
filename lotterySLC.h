#ifndef __LOTTERYSLC__
#define __LOTTERYSLC__

#include "event.h"

class LotterySLC : public Event {
	private:
		int blockID;
	public:
		LotterySLC(Cell &c, const int id);
		~LotterySLC();
		void event(Player *p);
};

#endif
