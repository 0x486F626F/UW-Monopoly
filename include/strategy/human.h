#ifndef __HUMAN_H__
#define __HUMAN_H__

#include "strategy.h"
#include "player.h"

class Human : public Strategy {
	private:
		std::string ropertyName;
	public:
		Human();
		~Human();
		std::string	getPropertyName();

		int		command(Player *p);
		bool	buyProperty(Cell *b, Player *p);
		int		unblock(Player *p, const int fee, const int itemID);
		int		tuition(const int fee, const int rate, Player *p);
};

#endif
