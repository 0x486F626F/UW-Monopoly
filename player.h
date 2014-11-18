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
		Player();
		~Player();
		Player(std::string s);

		char getInit();
		void setCurrentCell(Cell *c);
		void addProperty(Cell *c);
};
#endif
