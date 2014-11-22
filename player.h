#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>

class Cell;
class Strategy;

class Player {
	private:
	   //ID of the player
		int ID;
		//name of player
		std::string name;
		//number of dice the palyer roll each round
		int numDice;
		//pointer to the current position
		Cell *currentCell;
		int money;
		//what the player owns
		std::vector <Cell*> property;

		Strategy *stg;
		int		leftRoll;
		int		rest;
		bool	bankrupted;
		int		block;

	public:
		~Player();
		Player(const int ID, const std::string &s);
		
		//get ID of the player
		int getID();
		//get name initial of the player
		char getInit();
		//get name of player
		std::string getName();
		//place player to the destinated cell
		void setCurrentCell(Cell *c);
		//get current position
		Cell *getCurrentCell();
		//add a property to the player
		void addProperty(Cell *c);
		//remoce a property from a player
		void removeProperty(Cell *c);

		int getMoney();
		void setMoney(const int m);
		void addMoney(const int m);

		void	setStrategy(const int type);
		Strategy*	getStrategy();

		int		getLeftRoll();
		void	setLeftRoll(const int r);

		int		getRest();
		void	setRest(const int r);

		int		getBlock();
		void	setBlock(const int b);

		void	printInfo();
};	

#endif
