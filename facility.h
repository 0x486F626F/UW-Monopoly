#ifndef __FACILITY_H__
#define __FACILITY_H__

#include <string>
#include "cell.h"

class Player;
class Group;

class Facility : public Cell {
	private:
	   //get the text image of a facility cell. On top is the name of the facility and below is the current players in this cell
		void generateTextImage();
	public:
		Facility();
		Facility(const int i, const std::string &s);
};

#endif
