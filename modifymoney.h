#ifndef __MODIFYMONEY_H__
#define __MODIFYMONEY_H__

#include "event.h"

class ModifyMoney : public Event {
	private:
		int money;
	public:
		ModifyMoney(Cell &c, const int m);
		~ModifyMoney();
		void event(Player *p);
};

#endif
