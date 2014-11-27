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
      
      //get cell information, ID/name
		virtual int getID();
		virtual std::string getName();
		//add player to game at current cell
		virtual void addPlayer(Player *p);
		//remove player from current cell
		virtual void removePlayer(Player *p);
		//move player to current cell
		virtual void movePlayer(Player *p);
		//get cell image
		virtual std::vector <std::string> getTextImage();
		virtual void event(Player *p);
		virtual void generateTextImage();
      
      //get purchase price
		virtual int getCost();
		virtual void setCost(const int c);
		//cost of improvement
		virtual int getCostImprove();
		virtual void setCostImprove(const int c);
		//imporvement level
		virtual int getLevel();
		virtual int	getMaxLevel();
		virtual void setLevel(const int l);
		//get owner
		virtual Player *getOwner();
		virtual void setOwner(Player *p);
		virtual void swapOwner(Player *p1, Player *p2);
		//get monopoly group belonging
		virtual Group *getGroup();
		virtual void setGroup(Group *g);
		//tuition amount
		virtual void addRent(const int r);
		virtual int getRent(const int l);
		//property status
		virtual bool isSold();
		virtual bool isMortgaged();
		virtual void mortgage();
		virtual void unmortgage();
		virtual bool canBuy();
		virtual bool canImprove();
		virtual int getPrepaid();
		virtual void setPrepaid(const int p);
		virtual void reset();
};

#endif
