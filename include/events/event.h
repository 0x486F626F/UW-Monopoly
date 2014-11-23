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
		void addPlayer(Player *p);
		void removePlayer(Player *p);
		void movePlayer(Player *p);
		std::vector <std::string> getTextImage();
		void generateTextImage();

		int getCost();
		void setCost(const int c);
		int getCostImprove();
		void setCostImprove(const int c);
		int getLevel();
		void setLevel(const int l);
		Player *getOwner();
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);
		Group *getGroup();
		void setGroup(Group *g);
		void addRent(const int r);
		int getRent(const int l);
		bool isSold();
		bool isMortgaged();
		void mortgage();
		void unmortgage();
		bool canBuy();
		bool canImprove();
};

#endif
