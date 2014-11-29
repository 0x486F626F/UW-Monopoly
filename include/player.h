#ifndef __PLAYER_H__
#define __PLAYER_H__

#include <vector>
#include <string>

class Cell;
class Strategy;

class Player {
	private:
	   
		int ID;   //ID of the player
		
		std::string name;   //name of player
		char nameInit;
		int numDice;   //number of dice the palyer roll each round
		Cell *currentCell;   //pointer to the current position
		int money;
		std::vector <Cell*> property;   //what the player owns
		std::vector <int> item;

		Strategy *stg;
		int		leftRoll;
		int		rest;
		bool	bankrupted;
		int		block;

	public:
		~Player();
		Player(const int ID, const std::string &s);

		
		int		getID();   //get ID of the player
		
		char	getInit();   //get name initial of the player
		void	setInit(const char c);
		
		std::string	getName();   //get name of player
		void	setName(const std::string &s);
		void setCurrentCell(Cell *c);   //place player to the destinated cell
		Cell*	getCurrentCell();   //get current position
		void	addProperty(Cell *c);   //add a property to the player
		void	removeProperty(Cell *c);   //remoce a property from a player
		Cell*	getFirstProperty();
		Cell*	findProperty(const std::string &s);


		
		int		getMoney();   //access player's money balance
		void	setMoney(const int m);
		void	addMoney(const int m);
		
		int		cntProperty();   //calculate player's property worth

		
		void	setStrategy(const int type);   //set the human player type strategy
		Strategy*	getStrategy();

		
		int		getLeftRoll();   //how many more times can a player roll
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
