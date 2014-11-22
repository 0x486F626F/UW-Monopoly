#ifndef __LOTTERYNH_H__
#define __LOTTERYNH_H__

#include "event.h"

class NH : public Event {
	public:
		NH(Cell &c);
		~NH();
		void event(Player *p);
};

#endif
