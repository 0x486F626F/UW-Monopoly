#include "cell.h"

using namespace std;

Cell::Cell() {}
Cell::~Cell() {}

Cell::Cell(const int i, const std::string &s, const std::string &g) :
	ID(i), name(s), group(g) {}

int Cell::getID() { return ID; }

void Cell::setXCoords(const int x, const int y) { Xx = x, Xy = y; }

void Cell::addPlayer(Player *p) {
	p->setCurrentCell(this);
	currentPlayer.push_back(p);
}

void Cell::removePlayer(Player *p) {
	p->setCurrentCell(NULL);
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

vector <string> Cell::getTextImage() { 
	generateTextImage();
	return textImage; 
}
