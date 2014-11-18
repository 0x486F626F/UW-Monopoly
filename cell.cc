#include "cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {}
Cell::Cell(const string &s, const string &g) : name(s), group(g) {}
Cell::~Cell() {}

std::vector <std::string> Cell::getTextImage() { return textImage; }

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
