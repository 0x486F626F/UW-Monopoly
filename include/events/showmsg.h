#ifndef __SHOWMSG_H__
#define __SHOWMSG_H__

#include "event.h"
#include <string>

class ShowMsg : public Event {
	private:
		std::string msg;
	public:
		ShowMsg(Cell &c, const std::string &m);
		~ShowMsg();

		void event(Player *p);
};

#endif
