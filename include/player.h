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
		char nameInit;
		//number of dice the palyer roll each round
		int numDice;
		//pointer to the current position
		Cell *currentCell;
		int money;
		//what the player owns
		std::vector <Cell*> property;
		std::vector <int> item;

		Strategy *stg;
		int		leftRoll;
		int		rest;
		bool	bankrupted;
		int		block;

	public:
		~Player();
		Player(const int ID, const std::string &s);

		//get ID of the player
		int		getID();
		//get name initial of the player
		char	getInit();
		void	setInit(const char c);
		//get name of player
		std::string	getName();
		void	setName(const std::string &s);
		//place player to the destinated cell
		void setCurrentCell(Cell *c);
		//get current position
		Cell*	getCurrentCell();
		//add a property to the player
		void	addProperty(Cell *c);
		//remoce a property from a player
		void	removeProperty(Cell *c);
		Cell*	getFirstProperty();
		Cell*	findProperty(const std::string &s);


		//access player's money balance
		int		getMoney();
		void	setMoney(const int m);
		void	addMoney(const int m);
		//calculate player's property worth
		int		cntProperty();

		//set the human player type strategy
		void	setStrategy(const int type);
		Strategy*	getStrategy();

		//how many more times can a player roll
		int		getLeftRoll();
		void	setLeftRoll(const int r);

		int		getRest();
		void	setRest(const int r);

		int		getBlock();
		void	setBlock(const int b);

		bool	isBankrupted();		
		void	setBankrupted(const bool b);

		void	addItem(const int idItem);
		bool	removeItem(const int idItem);

		void	printAssets();
};	

#endif
