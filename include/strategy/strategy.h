#ifndef __STRATEGY_H__
#define __STRATEGY_H__
#include <string>

class Cell;
class Player;

class Strategy {
	public:
		Strategy();
		virtual ~Strategy() = 0;

		virtual std::string	getPropertyName() = 0;

		virtual int		command(Player *p) = 0;
		virtual int		lackMoney(Player *p, const int m) = 0;
		virtual bool	buyProperty(Cell *b, Player *p) = 0;
		virtual int		unblock(Player *p, const int fee, const int itemID) = 0;
		virtual int		tuition(const int fee, const int rate, Player *p) = 0;
		virtual int		prepaid(Player *p, Cell *c) = 0;
		virtual bool	tradeMM(Player* p1, Player* p2, const int m1, const int m2) = 0;
		virtual bool	tradeMP(Player* p1, Player* p2, const int m1, Cell* c2) = 0;
		virtual bool	tradePM(Player* p1, Player* p2, Cell* c1, const int m2) = 0;
		virtual bool	tradePP(Player* p1, Player* p2, Cell* c1, Cell* c2) = 0;
		virtual int		getChar() = 0;
};

#endif
