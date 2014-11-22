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
		//Board is setup as a singleton
		static Board *instance;

		static void cleanInstance();

		std::string savefile;
		bool testing;
		//determine the size of the board
		int width, height;
		//setup the number of players/cells/groups
		int numPlayer, numCell, numGroup;
		std::vector <Cell*> cells;
		std::vector <Player*> players;
		std::vector <Group*> groups;

		TextDisplay *td;
		//XDisplay *xd;

		Board(const std::string save, const bool testing);
		~Board();


		//load the map of the game in accordance to the map file
		void loadMap(const std::string &mapfile);
		//initialize a game of 6 players
		void initGame();
		void loadGame();
		//print the current state of the board
		void printBoard();
		
		void printPlayerInfo();

		// terminate a game and return false
		bool gameEnd();

	public:
		static Board *getInstance(const std::string save = "", const bool testing = 0);

		void movePlayerTo(const int idPlayer, const int idCell);
		void movePlayerForward(const int idPlayer, const int step);

		void startGame();
};
#endif
