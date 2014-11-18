#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include <string>
#include <vector>
#include "cell.h"

class Property : public Cell {
	private:
		int cost, costImprove;
		void generateTextImage();
		std::vector <int> rents;
	public:
		Property();	
		Property(const std::string &s, const std::string &g);
		void setCost(const int c);
		void setCostImprove(const int c);
		void addRent(const int r);
		void addPlayer(Player *p);
};
#endif
