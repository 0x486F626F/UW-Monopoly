#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>

class Player;
class Cell;
class Group;
class TextDisplay;
//class XDisplay;

class Board {
	private:
		static Board *instance;

		static void cleanInstance();

		std::string savefile;
		bool testing;
		int width, height;
		int numPlayer, numCell, numGroup;
		std::vector <Cell*> cells;
		std::vector <Player*> players;
		std::vector <Group*> groups;

		TextDisplay *td;
		//XDisplay *xd;
		
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
