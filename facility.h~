#ifndef __FACILITY_H__
#define __FACILITY_H__

#include <string>
#include "cell.h"

class Player;
class Group;

class Facility : public Cell {
	private:
	   //get the text image of a facility cell
		void generateTextImage();
	public:
		Facility();
		Facility(const int i, const std::string &s);
		
		//facility has no cost/improvement cost or rent
		void setCost(const int c);
		void setCostImprove(const int c);
		void addRent(const int r);
		//facility has no owner
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);
		//all facility is neither buyable or improvable, therefore return false when asked isBuyable()/isImprovable()
		bool isBuyable();
		bool isImproveable();
		//facilities belong to no group
		Group *getGroup();

		void event(Player *p);
};

#endif
