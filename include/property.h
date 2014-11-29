#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <string>
#include <vector>
#include "cell.h"

class Player;
class Group;

class Property : public Cell {
	private:
		int cost, costImprove, level, prepaid;
		std::vector <int> rents;
		bool sold, mortgaged;   //status of the property
		Player *owner;   //pointer to the owner of the property (null if no owner)
		Group *group;   //pointer to the group the property belongs to
		void generateTextImage();   //print the cell. On top is the owner, then seperated by a doted line then is the name of the property, below is the current players in this cell.

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
		int		getPrepaid();
		void	setPrepaid(const int p);
		void	reset();
		void	drawXImage();
};

#endif
