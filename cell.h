#ifndef __CELL_H__
#define __CELL_H__
#include <string>
#include <vector>
#include "player.h"

const int CELLWIDTH = 7;
const int CELLHEIGHT = 4;

class Player;

class Cell {
	protected:
		std::string name;
		std::string group;
		std::vector <std::string> textImage;
		Cell *prev, *next;
		std::vector <Player *> currentPlayer;

		Cell();
		Cell(const std::string &s, const std::string &g);
		~Cell();
		virtual void generateTextImage() = 0;
	public:
		void print();
};
#endif
