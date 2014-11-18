#include "cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {}
Cell::Cell(const string &s, const string &g) : name(s), group(g) {}
Cell::~Cell() {}

void Cell::addPlayer(Player *p) {
	p->setCurrentCell(this);
	currentPlayer.push_back(p);
	generateTextImage();
}

std::vector <std::string> Cell::getTextImage() { return textImage; }
