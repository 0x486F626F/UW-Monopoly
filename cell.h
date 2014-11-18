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
		virtual void setCost(const int c) = 0;
		virtual void setCostImprove(const int c) = 0;
		virtual void addRent(const int c) = 0;
		virtual void addPlayer(Player *p) = 0;

		std::vector <std::string> getTextImage();
};
#endif
