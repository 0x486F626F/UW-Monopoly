#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>
#include "cell.h"
#include "player.h"

class Event : public Cell {
	private:
		void generateTextImage();
	public:
		Event();
		Event(const int i, const std::string &s, const std::string &g);
		void setCost(const int c) {}
		void setCostImprove(const int c) {}
		void addRent(const int r) {}
		void setOwner(Player *p) {}
		void removeOwner(Player *p) {}
};
#endif
