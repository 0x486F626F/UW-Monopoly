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
		void loadMap(std::string mapfile);
	public:
		Board();
		Board(std::string &mapfile);
		~Board();

		void printBoard();
};
#endif
