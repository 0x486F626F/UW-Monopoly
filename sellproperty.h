#ifndef __SELLPROPERTY_H__
#define __SELLPROPERTY_H__
#include <vector>
#include <string>
#include "event.h"

class Player;
class Group;

class SellProperty : public Event {
	private:
		void generateTextImage();
	public:
		SellProperty(Cell &c);
		~SellProperty();

		void setCost(const int c);
		void setCostImprove(const int c);
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

		void event(Player *p);
};

#endif
