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
		static Behavior*	instance;
		static void			cleanInstance();

		Behavior();
		~Behavior();

	public:
		static Behavior*	getInstance();

		std::vector <int>	roll(const bool testing = 0);

		void	movePlayerTo(Player *p, const int idCell, const bool callEvent = 1);
		void	movePlayerForward(Player *p, const int step);

		void	modifyMoney(Player *p, const int m);
		void	setMoney(Player *P, const int m);
		int		cntProperty(Player *p);
		void	block(Player *p);
		void	addBlock(Player *p);
		void	unblock(Player *p);
		int		getBlock(Player *p);
		bool	affordable(Player *p, const int m);
		void	getOSAP(Player *p);
		bool	same(Player *p1, Player *p2);
		//void	bankrupt(Player *p);
		//void	giveItem(Player *p, Item *it);
		//void	useItem(Player *p, Item *it);

		bool	strategyBuyProperty(Player *p, Cell *c);
		int		strategyUnblock(Player *p, const int fee, const int itemID);
		int		strategyTuition(const int fee, const int rate, Player *p);

		void	buyProperty(Player *p, Cell *c);
		void	buyImprove(Player *p, const std::string &s);
		void	sellImprove(Player *p, const std::string &s);
		void	mortgage(Player *p, const std::string &s);
		void	unmortgage(Player *p, const std::string &s);
		void	printAssets(Player *p);

		void	printMsg(const std::string &s);

		bool	isMonopoly(Group *g);

		int		numDice();

		int		getItemID(const std::string &s);
};

#endif
