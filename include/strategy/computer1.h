#ifndef __COMPUTER1_H__
#define __COMPUTER1_H__

#include "strategy.h"
#include "player.h"

class Computer1 : public Strategy {
	private:
		std::string propertyName;
	public:
		Computer1();
		~Computer1();

		std::string	getPropertyName();

		
		int		command(Player *p);   //what is the command output
		bool	buyProperty(Cell *b, Player *p);   //decision to purchase property
		int		unblock(Player *p, const int fee, const int itemID);   //get decision on how to free from DC Tim Line
		int		tuition(const int fee, const int rate, Player *p);   //decision on how to pay tuition
		int		lackMoney(Player *p, const int m);
		int		prepaid(Player *p, Cell *c);
		bool	tradeMM(Player* p1, Player* p2, const int m1, const int m2);
		bool	tradeMP(Player* p1, Player* p2, const int m1, Cell* c2);
		bool	tradePM(Player* p1, Player* p2, Cell* c1, const int m2);
		bool	tradePP(Player* p1, Player* p2, Cell* c1, Cell* c2);
};

#endif
