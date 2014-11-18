#ifndef __CELL_H__
#define __CELL_H__

#include <string>
#include <vector>

#include "player.h"

const int CELLWIDTH = 7;
const int CELLHEIGHT = 4;

class Player;

class Cell {
	protected:
		int ID;
		std::string name, group;
		std::vector <std::string> textImage;
		std::vector <Player*> currentPlayer;

		virtual void generateTextImage() = 0;

	public:
		Cell();
		virtual ~Cell();
		Cell(const int i, const std::string &s, const std::string &g);

		virtual void setCost(const int c) = 0;
		virtual void setCostImprove(const int c) = 0;
		virtual void addRent(const int r) = 0;
		virtual void setOwner(Player *p) = 0;
		virtual void swapOwner(Player *p1, Player *p2) = 0;

		//virtual void event(Player *p) = 0;

		int getID();
		void addPlayer(Player *p);
		void removePlayer(Player *p);
		void movePlayer(Player *p);

		std::vector <std::string> getTextImage();
};
#endif
