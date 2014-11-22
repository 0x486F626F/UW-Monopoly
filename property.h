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
		//pointer to the owner of the property (null if no owner)
		Player *owner;
		//pointer to the group the property belongs to
		Group *group;
      //print the cell. On top is the owner, then seperated by a doted line then is the name of the property, below is the current players in this cell.
		void generateTextImage();

	public:
		Property();
		Property(const int i, const std::string &s);
		int		getCost();
		void	setCost(const int c);
		int		getCostImprove();
		void	setCostImprove(const int c);
		int		getLevel();
		int		getMaxLevel();
		void	setLevel(const int l);
		Player*	getOwner();
		void	setOwner(Player *p);
		Group*	getGroup();
		void	setGroup(Group *g);
		void	addRent(const int r);
		int		getRent(const int l);
		bool	isSold();
		bool	isMortgaged();
		void	mortgage();
		void	unmortgage();
		bool	canBuy();
		bool	canImprove();
};

#endif
