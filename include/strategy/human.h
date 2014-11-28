#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "strategy.h"
#include "player.h"

class Human : public Strategy {
	private:
		std::string propertyName;
	public:
		Human();
		~Human();

		std::string	getPropertyName();

		//what is the command output
		int		command(Player *p);
		//decision to purchase property
		bool	buyProperty(Cell *b, Player *p);
		//get decision on how to free from DC Tim Line
		int		unblock(Player *p, const int fee, const int itemID);
		//decision on how to pay tuition
		int		tuition(const int fee, const int rate, Player *p);
		int		lackMoney(Player *p, const int m);
		int		prepaid(Player *p, Cell *c);
		bool	tradeMM(Player* p1, Player* p2, const int m1, const int m2);
		bool	tradeMP(Player* p1, Player* p2, const int m1, Cell* c2);
		bool	tradePM(Player* p1, Player* p2, Cell* c1, const int m2);
		bool	tradePP(Player* p1, Player* p2, Cell* c1, Cell* c2);
		int		getChar();
};

#endif
