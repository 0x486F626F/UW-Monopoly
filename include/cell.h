#ifndef __CELL_H__
#define __CELL_H__

#include <vector>
#include <string>
#include "player.h"

const int CELLWIDTH = 7;
const int CELLHEIGHT = 4;

class Player;
class Group;

class Cell {
	protected:
		int ID;
		int x, y;
		std::string name;
		std::vector <Player*> currentPlayer;

		std::vector <std::string> textImage;


	public:
		Cell();
		Cell(const int i, const std::string &s);
		virtual ~Cell();
      
      
		virtual int getID();   //get cell information, ID/name
		virtual std::string getName();
		virtual int getX();
		virtual int getY();
		virtual void setX(const int a);
		virtual void setY(const int a);
		
		virtual void addPlayer(Player *p);   //add player to game at current cell
		
		virtual void removePlayer(Player *p);   //remove player from current cell
		
		virtual void movePlayer(Player *p);   //move player to current cell
		
		virtual std::vector <std::string> getTextImage();   //get cell image
		virtual void event(Player *p);
		virtual void generateTextImage() = 0;
		virtual void drawXImage() = 0;
      
      
		virtual int getCost();   //get purchase price
		virtual void setCost(const int c);
		
		virtual int getCostImprove();   //cost of improvement
		virtual void setCostImprove(const int c);
		
		virtual int getLevel();   //imporvement level
		virtual int	getMaxLevel();
		virtual void setLevel(const int l);
		
		virtual Player *getOwner();   //get owner information
		virtual void setOwner(Player *p);
		virtual void swapOwner(Player *p1, Player *p2);
		
		virtual Group *getGroup();   //get monopoly group belonging
		virtual void setGroup(Group *g);
		
		virtual void addRent(const int r);   //tuition amount
		virtual int getRent(const int l);
		
		virtual bool isSold();   //property status
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
