#ifndef __PROPERTY_H__
#define __PROPERTY_H__

#include <string>
#include <vector>

#include "cell.h"
#include "player.h"

class Property : public Cell {
	private:
		int cost, costImprove;
		std::vector <int> rents;
		bool sold, mortgaged;
		Player *owner;

		void generateTextImage();

	public:
		Property();
		Property(const int i, const std::string &s, const std::string &g);
		
		void setCost(const int c);
		void setCostImprove(const int c);
		void addRent(const int r);
		void setOwner(Player *p);
		void swapOwner(Player *p1, Player *p2);

		//void event(Player *p);
};

#endif
