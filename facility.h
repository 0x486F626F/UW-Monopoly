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
		
		void setCost();
		void setCostImprove();
		void addRent();
		void setOwner();
		void swapOwner();
		bool isBuyable();
		bool isImproveable();
		Group *getGroup();

		void event();
};

#endif
