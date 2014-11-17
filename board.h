#ifndef __BOARD_H__
#define __BOARD_H__
#include <vector>
#include "cell.h"
class Board {
	private:
		static Board *instance;

		int width, height;
		std::vector <Cell*> cells;

		Board *getInstance();
		void loadMap(const std::string &mapfile);
	public:
		Board();
		Board(const std::string &mapfile);
		~Board();

		void printAll();
};
#endif
