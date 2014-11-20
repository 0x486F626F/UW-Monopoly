#ifndef __SELLPROPERTY_H__
#define __SELLPROPERTY_H__
#include "event.h"

class SellProperty : public Event {
	private:
	public:
		SellProperty(Cell &c);
		~SellProperty();

		void event(Player *p);
};

#endif
