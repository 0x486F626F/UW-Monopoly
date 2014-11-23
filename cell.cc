#include "cell.h"
#include "player.h"
#include <iostream>
using namespace std;

Cell::Cell() {}
Cell::Cell(const int i, const std::string &s) : ID(i), name(s) {}
Cell::~Cell() {}

int Cell::getID() { return ID; }

string Cell::getName() { return name; }

void Cell::addPlayer(Player *p) {
	p->setCurrentCell(this);
	currentPlayer.push_back(p);
}

void Cell::removePlayer(Player *p) {
   //removed player does not exist on board
	p->setCurrentCell(NULL);
	//remove player from player list
	for(vector <Player*>::iterator i = currentPlayer.begin(); i != currentPlayer.end(); i ++)
		if((*i)->getID() == p->getID()) {
			currentPlayer.erase(i);
			break;
		}
}

void Cell::movePlayer(Player *p) {
	p->getCurrentCell()->removePlayer(p);
	addPlayer(p);
}

void	Cell::generateTextImage() {}

vector <string> Cell::getTextImage() { 
	generateTextImage();
	return textImage; 
}

void	Cell::event(Player *p) {}

int		Cell::getCost() { return 0; }
void	Cell::setCost(const int c) {}
int		Cell::getCostImprove() { return 0; }
void	Cell::setCostImprove(const int c) {}
int		Cell::getLevel() { return 0; }
int		Cell::getMaxLevel() { return 0; }
void	Cell::setLevel(const int l) {}
Player*	Cell::getOwner() { return NULL; }
void	Cell::setOwner(Player *p) {}
void	Cell::swapOwner(Player *p1, Player *p2) {}
Group*	Cell::getGroup() { return NULL; }
void	Cell::setGroup(Group *g) {}
void	Cell::addRent(const int r) {}
int		Cell::getRent(const int l) { return 0; }
bool	Cell::isSold() { return false; }
bool	Cell::isMortgaged() { return false; }
void	Cell::mortgage() {}
void	Cell::unmortgage() {}
bool	Cell::canBuy() {return false;}
bool	Cell::canImprove() {return false;}
