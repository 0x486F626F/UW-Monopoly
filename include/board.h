#ifndef __BOARD_H__
#define __BOARD_H__

#include <vector>
#include <string>

class Player;
class Cell;
class Group;
class Behavior;
class TextDisplay;
class XDisplay;

class Board {
	private:
		
		static Board *instance;   //Board is setup as a singleton

		static void cleanInstance();

		std::string savefile;
		bool testing;
		
		int width, height;   //determine the size of the board	
		int numPlayer, numCell, numGroup, numDice;   //setup the number of players/cells/groups
		int nowPlayer;
		std::vector <Cell*> cells;
		std::vector <Player*> players;
		std::vector <Group*> groups;

		Behavior *bh;
		TextDisplay *td;
		XDisplay *xd;

		Board(const std::string save, const bool testing);
		~Board();


		
		void loadMap(const std::string &mapfile);   //load the map of the game in accordance to the map file
		void initGame();   //initialize a game
		void loadGame(const std::string savefile);

		bool gameEnd();   // terminate a game and return false

	public:
		static Board *getInstance(const std::string save = "", const bool testing = 0);

		void movePlayerTo(const int idPlayer, const int idCell, const bool callEvent = 1);
		void movePlayerForward(const int idPlayer, const int step);
		Player*	getPlayer(const char init);
		void printBoard();   //print the current state of the board
		void saveGame(const std::string saveFile);

		void startGame();
};
#endif
