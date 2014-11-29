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

		//access cell purchase cost and improvement cost and level
		int getCost();
		void setCost(const int c);
		int getCostImprove();
		void setCostImprove(const int c);
		int getLevel();
		int		getMaxLevel();
		void setLevel(const int l);
		//get and set owner
		Player *getOwner();
		void setOwner(Player *p);
		//swap owner for trade
		void swapOwner(Player *p1, Player *p2);
		//get the group that property belongs to
		Group *getGroup();
		void setGroup(Group *g);
		void addRent(const int r);
		int getRent(const int l);
		//access cell status
		bool isSold();
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
