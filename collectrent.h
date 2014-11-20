#ifndef __COLLECTRENT_H__
#define __COLLECTRENT_H__

#include "event.h"

class CollectRent : public Event {
	private:
	public:
		CollectRent(Cell &c);
		~CollectRent();

		void event(Player *p);
};

#endif
