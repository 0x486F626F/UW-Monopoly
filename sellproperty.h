#ifndef __SELLPROPERTY_H__
#define __SELLPROPERTY_H__
#include <vector>
#include <string>
#include "event.h"

class Player;
class Group;

class SellProperty : public Event {
	private:
	public:
		SellProperty(Cell &c);
		~SellProperty();

		void event(Player *p);
};

#endif
