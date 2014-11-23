#ifndef __TUITION_H__
#define __TUITION_H__

#include "event.h"

class Tuition : public Event {
	public:
		Tuition(Cell &c);
		~Tuition();
		void event(Player *p);
};

#endif
