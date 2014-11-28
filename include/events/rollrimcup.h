#ifndef __ROLLRIMCUP_H__
#define __ROLLRIMCUP_H__

#include "event.h"

class RollRimCup : public Event {
	public:
		RollRimCup(Cell &c);
		~RollRimCup();
		void event(Player* p);
};

#endif
