#ifndef __BEHAVIOR_H__
#define __BEHAVIOR_H__

#include <vector>

class Player;
class Cell;
class Item;

class Behavior {
	private:
		static Behavior*	instance;
		static void			cleanInstance();

		Behavior();
		~Behavior();

	public:
		static Behavior*	getInstance();

		std::vector <int>	roll();
		std::vector <int>	roll(std::vector <int> v);

		void	movePlayerTo(Player *p, Cell *c);
		void	movePlayerForward(Player *p, const int step);

		void	modifyMoney(Player *p, const int m);
		void	setMoney(Player *P, const int m);
		void	block(Player *p);
		void	addBlock(Player *p);
		void	unblock(Player *p);
		//void	bankrupt(Player *p);
		//void	giveItem(Player *p, Item *it);
		//void	useItem(Player *p, Item *it);

		void	buyProperty(Player *p, Cell *c);
		void	buyImprove(Cell *c);
		void	sellImprove(Cell *c);
		void	mortgage(Cell *c);
		void	unmortgage(Cell *c);
};

#endif
