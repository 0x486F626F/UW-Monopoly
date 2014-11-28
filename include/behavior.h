#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__

#include <vector>
#include <string>

class Player;
class Cell;
class Group;

class Behavior {
	private:
	   //Behavior is implemented as a singleton, there are at all time one behavior that can be called
		static Behavior*	instance;
		static void			cleanInstance();

		bool	testing;
		int		numRimCup;
      
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


		void	setTesting(const bool t);
		//access to the money balance of a player
		void	modifyMoney(Player *p, const int m);
		void	transferMoney(Player *p1, Player *p2, const int m);
		void	setMoney(Player *P, const int m);
		//calculate the net-worth of a player
		int		cntProperty(Player *p);
		//block a player(when sent the Tim Line)
		void	block(Player *p);
		void	addBlock(Player *p);
		void	unblock(Player *p);
		int		getBlock(Player *p);
		bool	affordable(Player *p, const int m); //check if the player can afford
		void	getOSAP(Player *p);
		bool	same(Player *p1, Player *p2);
		void	bankrupt(Player *p, Player *p2);
		int		getItemID(const std::string &itemName);
		void	addItem(Player *p, const std::string &itemName);
		bool	removeItem(Player *p, const std::string &itemName);

		//player's decision to purchase a certain property
		bool	strategyBuyProperty(Player *p, Cell *c);
		//player's decision to free from Tim Line
		int		strategyUnblock(Player *p, const int fee, const int itemID);
		//collecting tuition amount
		int		strategyTuition(const int fee, const int rate, Player *p);
		int		strategyCommand(Player *p);
		int		strategyLackMoney(Player *p, const int m);
		std::string strategyGetPropertyName(Player *p);
		int		strategyPrepaid(Player *p, Cell *c);


		//purchase property and (sell) improvement
		void	buyProperty(Player *p, Cell *c);
		void	buyImprove(Player *p, const std::string &s);
		void	sellImprove(Player *p, const std::string &s);
		void	transferOwnership(Cell *c, Player *p);
		void	mortgage(Player *p, const std::string &s);
		void	unmortgage(Player *p, const std::string &s);
		void	printAssets(Player *p);

		void	printMsg(const std::string &s);

		//check if the block is monopolized
		bool	isMonopoly(Group *g);

		void	printBoard();
		void	playRound(Player *p);
		void	lackMoney(const int m, Player *p, Player *p2 = NULL);

		int		numDice();
		int		getNumRimCup();
		void	setNumRimCup(const int num);

		void	trade(Player* p1, Player* p2, const std::string condition1, const std::string condition2);
};

#endif
