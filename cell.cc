#include "cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {}
Cell::Cell(const int i, const string &s, const string &g) : ID(i), name(s), group(g) {}
Cell::~Cell() {}

std::vector <std::string> Cell::getTextImage() { return textImage; }

int Cell::getID() { return ID; }

void Cell::addPlayer(Player *p) {
	p->setCurrentCell(this);
	currentPlayer.push_back(p);
	generateTextImage();
}

void Cell::removePlayer(Player *p) {
	p->setCurrentCell(NULL);
	for(vector <Player *>::iterator i = currentPlayer.begin(); i != currentPlayer.end(); i ++)
		if((*i)->getName() == p->getName()) {
			currentPlayer.erase(i);
			break;
		}
	generateTextImage();
}
