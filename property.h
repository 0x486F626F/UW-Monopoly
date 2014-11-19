#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <string>
#include <vector>
#include "cell.h"

class Player;
class Group;

class Property : public Cell {
	private:
		int cost, costImprove, level;
		std::vector <int> rents;
		bool sold, mortgaged;
		bool buyable, improveable;
		Player *owner;
		Group *group;

		void generateTextImage();

	public:
		Property();
		Property(const int i, const std::string &s);
		
		void setCost(const int c);
		void setCostImprove(const int c);
		void addRent(const int r);
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);
		Group *getGroup();
		bool isBuyable();
		bool isImproveable();
		
		int getOwnerID();
		void setGroup(Group *g);

		//void event(Player *p);
};

#endif
