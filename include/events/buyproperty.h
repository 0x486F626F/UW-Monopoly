#ifndef __SELLPROPERTY_H__
#define __SELLPROPERTY_H__
#include "event.h"

class BuyProperty : public Event {
	private:
	public:
		BuyProperty(Cell &c);
		~BuyProperty();

		void event(Player *p);
};

#endif
