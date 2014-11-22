#ifndef __BLOCKTIMLINE_H__
#define __BLOCKTIMLINE_H__

#include "event.h"
#include <string>


//works for DC Tims Line
class TimLine : public Event {
	private:
		int fee;
		std::string itemname;
	public:
		TimLine(Cell &c, const int f, const std::string i);
		~TimLine();

		void event(Player *p);
};

#endif
