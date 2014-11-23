#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "strategy.h"
#include "player.h"

class Human : public Strategy {
	public:
		Human();
		~Human();
		int		command(Player *p);
		bool	buyProperty(Cell *b, Player *p);
		int		unblock(Player *p, const int fee, const int itemID);
		int		tuition(const int fee, const int rate, Player *p);
};

#endif
