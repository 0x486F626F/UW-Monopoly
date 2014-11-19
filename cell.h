#ifndef __CELL_H__
#define __CELL_H__

#include <string>
#include <vector>

const int CELLWIDTH = 7;
const int CELLHEIGHT = 4;

class Player;
class Group;

class Cell {
	protected:
		int ID;
		std::string name;
		std::vector <std::string> textImage;
		int Xx, Xy;
		std::vector <std::vector <int> > XImage;
		std::vector <Player*> currentPlayer;


	public:
		Cell();
		virtual ~Cell();
		Cell(const int i, const std::string &s);

		virtual void generateTextImage() = 0;
		virtual void setCost(const int c) = 0;
		virtual void setCostImprove(const int c) = 0;
		virtual void addRent(const int r) = 0;
		virtual void setOwner(Player *p) = 0;
		virtual void swapOwner(Player *p1, Player *p2) = 0;
		virtual Group *getGroup() = 0;
		virtual bool isBuyable() = 0;
		virtual bool isImproveable() = 0;

		virtual void event(Player *p) = 0;

		virtual int getID();
		virtual std::string getName();
		virtual void setXCoords(const int x, const int y);
		virtual void addPlayer(Player *p);
		virtual void removePlayer(Player *p);
		virtual void movePlayer(Player *p);

		virtual std::vector <std::string> getTextImage();
};
#endif
