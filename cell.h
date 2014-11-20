#ifndef __CELL_H__
#define __CELL_H__

#include <vector>
#include <string>

const int CELLWIDTH = 7;
const int CELLHEIGHT = 4;

class Player;
class Group;

class Cell {
	protected:
		int ID;
		std::string name;
		std::vector <Player*> currentPlayer;

		std::vector <std::string> textImage;


	public:
		Cell();
		Cell(const int i, const std::string &s);
		virtual ~Cell();

		virtual int getID();
		virtual std::string getName();
		virtual void addPlayer(Player *p);
		virtual void removePlayer(Player *p);
		virtual void movePlayer(Player *p);
		virtual std::vector <std::string> getTextImage();
		virtual void event(Player *p);
		virtual void generateTextImage();

		virtual int getCost();
		virtual void setCost(const int c);
		virtual int getCostImprove();
		virtual void setCostImprove(const int c);
		virtual int getLevel();
		virtual void setLevel(const int l);
		virtual Player *getOwner();
		virtual void setOwner(Player *p);
		virtual void swapOwner(Player *p1, Player *p2);
		virtual Group *getGroup();
		virtual void setGroup(Group *g);
		virtual void addRent(const int r);
		virtual int getRent(const int l);
		virtual bool isSold();
		virtual bool isMortgaged();
		virtual void mortgage();
		virtual void unmortgage();
		virtual bool canBuy();
		virtual bool canImprove();
};

#endif
