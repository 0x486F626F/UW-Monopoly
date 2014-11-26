#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__

#include <vector>
#include <string>

class Player;
class Cell;
class Item;
class Group;

class Behavior {
	private:
	   //Behavior is implemented as a singleton, there are at all time one behavior that can be called
		static Behavior*	instance;
		static void			cleanInstance();
      
      //constructor and destructor
		Behavior();
		~Behavior();

	public:
		static Behavior*	getInstance();
      
      //testing roll, which we will choose the number that is rolled out
		std::vector <int>	roll(const bool testing = 0);
      //move player to a particular cell
		void	movePlayerTo(Player *p, const int idCell, const bool callEvent = 1);
		//check if the player's next move will pass the OSAP cell (like a move scanner)
		void	movePlayerForward(Player *p, const int step);
      
      
      //access to the money balance of a player
		void	modifyMoney(Player *p, const int m);
		void	setMoney(Player *P, const int m);
		//calculate the net-worth of a player
		int		cntProperty(Player *p);
		//block a player(when sent the Tim Line)
		void	block(Player *p);
		void	addBlock(Player *p);
		void	unblock(Player *p);
		int		getBlock(Player *p);
		//check if the player can afford
		bool	affordable(Player *p, const int m);
		void	getOSAP(Player *p);
		bool	same(Player *p1, Player *p2);
		//void	bankrupt(Player *p);
		//void	giveItem(Player *p, Item *it);
		//void	useItem(Player *p, Item *it);
      
      //player's decision to purchase a certain property
		bool	strategyBuyProperty(Player *p, Cell *c);
		//player's decision to free from Tim Line
		int		strategyUnblock(Player *p, const int fee, const int itemID);
		//collecting tuition amount
		int		strategyTuition(const int fee, const int rate, Player *p);
      
      
      //purchase property and (sell) improvement
		void	buyProperty(Player *p, Cell *c);
		void	buyImprove(Player *p, const std::string &s);
		void	sellImprove(Player *p, const std::string &s);
		void	mortgage(Cell *c);
		void	unmortgage(Cell *c);

		void	printMsg(const std::string &s);
      
      //check if the block is monopolized
		bool	isMonopoly(Group *g);

		int		numDice();

		int		getItemID(const std::string &s);
};

#endif
