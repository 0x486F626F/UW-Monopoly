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
		//status of the property
		bool sold, mortgaged;
		//if the property id buyable/improvable
		bool buyable, improveable;
		//pointer to the owner of the property (null if no owner)
		Player *owner;
		//pointer to the group the property belongs to
		Group *group;
      //print the cell. On top is the owner, then seperated by a doted line then is the name of the property, below is the current players in this cell.
		void generateTextImage();

	public:
		Property();
		Property(const int i, const std::string &s);
		
		//set the cost of the property
		void setCost(const int c);
		//set the improvement cost
		void setCostImprove(const int c);
		//update the current rent amount
		void addRent(const int r);
		//set the owner of the property
		void setOwner(Player *p);
		//swap ownership
		void swapOwner(Player *p1, Player *p2);
		//get the group information
		Group *getGroup();
		//check if the property is buyable/improvable
		bool isBuyable();
		bool isImproveable();
		
		//get owner ID
		int getOwnerID();
		//set group belonging
		void setGroup(Group *g);
      //possible events on this property
		void event(Player *p);
};

#endif
