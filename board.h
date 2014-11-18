#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>

class TextDisplay;
class XDisplay;
class Player;
class Cell;

class Board {
	private:
		static Board *instance;

		static void cleanInstance();

		std::string savefile;
		bool testing;
		int width, height;
		int numPlayer, numCell;
		std::vector <Cell*> cells;
		std::vector <Player*> players;

		TextDisplay *td;
		XDisplay *xd;
		
		Board(const std::string save, const bool testing);
		~Board();

		void loadMap(const std::string &mapfile);
		void initGame();
		void loadGame();
		void printBoard();

		bool gameEnd();
		void movePlayer(Player *p, Cell *s, Cell *g);

	public:
		static Board *getInstance(const std::string save, const bool testing);

		void startGame();
};
#endif
