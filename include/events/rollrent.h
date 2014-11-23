#ifndef __ROLLRENT_H__
#define __ROLLRENT_H__

#include "event.h"

class RollRent : public Event {
	public:
		RollRent(Cell &c);
		~RollRent();
		void event(Player *p);
};

#endif
