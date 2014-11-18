#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include <string>
#include <vector>
#include "cell.h"
#include "player.h"

class Property : public Cell {
	private:
		int cost, costImprove;
		void generateTextImage();
		std::vector <int> rents;
		bool sold, mortgaged;
		Player *owner;
	public:
		Property();	
		Property(const std::string &s, const std::string &g);
		void setCost(const int c);
		void setCostImprove(const int c);
		void addRent(const int r);
		void setOwner(Player *p);
};
#endif
