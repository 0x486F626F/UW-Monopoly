#include "board.h"

#include <iostream>
#include <sstream>
using namespace std;

Board::Board() {}
Board::~Board() {}


Board::Board(string &mapfile) {
	td = TextDisplay::getInstance();
	td->clean();

	istringstream stream(mapfile.c_str());
	stream >> width >> height;
	int totCell = width * 2 + height * 2 - 4;
	for(int i = 1; i <= totCell; i ++) {
		string name, group;
		getline(stream, name);
		getline(stream, group);
		td->addTag(name);
	}
}

void Board::printBoard() {
	td->printBoard(width, height);
}
