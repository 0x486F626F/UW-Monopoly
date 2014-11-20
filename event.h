#ifndef __EVENT_H__
#define __EVENT_H__

#include "cell.h"

class Event : public Cell {
	protected:
		Cell &theCell;
		Event(Cell &c);
		~Event();
		void generateTextImage();
	public:
		void setCost(const int c);
		int getCost();
		void setCostImprove(const int c);
		int getCostImprove();
		void addRent(const int r);
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);
		Group *getGroup();
		bool isBuyable();
		bool isImproveable();

		int getID();
		std::string getName();
		void setXCoords(const int x, const int y);
		void addPlayer(Player *p);
		void removePlayer(Player *p);
		void movePlayer(Player *p);

		std::vector <std::string> getTextImage();


};

#endif
