#ifndef __LOTTERYNH_H__
#define __LOTTERYNH_H__

#include "event.h"

class LotteryNH : public Event {
	public:
		LotteryNH(Cell &c);
		~LotteryNH();
		void event(Player *p);
};

#endif
