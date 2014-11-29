#ifndef __EVENT_H__
#define __EVENT_H__

#include "cell.h"

class Behavior;

class Event : public Cell {
	protected:
		Cell &theCell;
		Event(Cell &c);
		~Event();
		Behavior *bh;
	public:
		int getID();
		std::string getName();
		int getX();
		int getY();
		void setX(const int a);
		void setY(const int a);
		void addPlayer(Player *p);
		void removePlayer(Player *p);
		void movePlayer(Player *p);
		std::vector <std::string> getTextImage();
		void generateTextImage();

		
		int getCost();   //access cell purchase cost and improvement cost and level
		void setCost(const int c);
		int getCostImprove();
		void setCostImprove(const int c);
		int getLevel();
		int		getMaxLevel();
		void setLevel(const int l);
		
		Player *getOwner();   //get and set owner
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);   //swap owner for trade
		
		Group *getGroup();   //get the group that property belongs to
		void setGroup(Group *g);
		void addRent(const int r);
		int getRent(const int l);
		
		bool isSold();   //access cell status
		bool isMortgaged();
		void mortgage();
		void unmortgage();
		bool canBuy();
		bool canImprove();
		int		getPrepaid();
		void	setPrepaid(const int p);
		void	reset();
		void	drawXImage();
};

#endif
