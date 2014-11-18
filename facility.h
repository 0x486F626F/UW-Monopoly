#ifndef __FACILITY_H__
#define __FACILITY_H__

#include <string>

#include "cell.h"

class Facility : public Cell {
	private:
		void generateTextImage();
	public:
		Facility();
		Facility(const int i, const std::string &s, const std::string &g);
		
		void setCost(const int c) {}
		void setCostImprove(const int c) {}
		void addRent(const int r) {}
		void setOwner(Player *p) {}
		void swapOwner(Player *p1, Player *p2) {}

		//void event(Player *p);
};

#endif
