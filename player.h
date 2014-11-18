#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>

#include "cell.h"
#include "dice.h"

class Cell;

class Player {
	private:
		int ID;
		std::string name;
		int numDice;
		Dice *dice;
		Cell *currentCell;
		std::vector <Cell*> property;

	public:
		~Player();
		Player(const int ID, const std::string &s);
		
		int getID();
		char getInit();
		std::string getName();
		void setCurrentCell(Cell *c);
		Cell *getCurrentCell();
		void addProperty(Cell *c);
		void removeProperty(Cell *c);
		int roll(const bool testing);

};	

#endif
