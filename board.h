#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "cell.h"
#include "textdisplay.h"
class Board {
	private:
		static Board *instance;

		int width, height;
		std::vector <Cell*> cells;
		TextDisplay *td;

		Board *getInstance();
		void loadMap(const std::string &mapfile);
		void setPlayer(Player *p, Cell *c);
	public:
		Board();
		Board(const std::string &mapfile);
		~Board();

		void printAll();
};
#endif
