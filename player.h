#ifndef __PLAYER_H__
#define __PLAYER_H__
#include <vector>
#include <string>
#include "cell.h"

class Cell;

class Player {
	private:
		std::string name;
		Cell *currentCell;
		std::vector <Cell *> property;
	public:
		char getInit();
};
#endif
