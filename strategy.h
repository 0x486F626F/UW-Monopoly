#ifndef __STRATEGY_H__
#define __STRATEGY_H__

class Cell;
class Player;

class Strategy {
	public:
		Strategy();
		virtual ~Strategy() = 0;

		virtual int		command(Player *p) = 0;
		virtual bool	buyProperty(Cell *b, Player *p) = 0;
};

#endif
