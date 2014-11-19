#ifndef __GROUP_H__
#define __GROUP_H__

#include <vector>
#include <string>

class Cell;

class Group {
	private:
		int ID;
		std::string name;
		std::vector <Cell*> cell;
};

#endif
