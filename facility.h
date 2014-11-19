#ifndef __FACILITY_H__
#define __FACILITY_H__

#include <string>
#include "cell.h"

class Player;
class Group;

class Facility : public Cell {
	private:
		void generateTextImage();
	public:
		Facility();
		Facility(const int i, const std::string &s);
		
		void setCost(const int c) {}
		void setCostImprove(const int c) {}
		void addRent(const int r) {}
		void setOwner(Player *p) {}
		void swapOwner(Player *p1, Player *p2) {}
		bool isBuyable() { return false; }
		bool isImproveable() { return false; }
		Group *getGroup() { return NULL; }

		void event(Player *p) {}
};

#endif
