#include "board.h"

#include <iostream>
#include <sstream>
using namespace std;

Board::Board() {}
Board::~Board() {}

Board::Board(const string &mapfile) {
	loadMap(mapfile)
}

void loadMap(const string &mapfile) {
	istringstream stream(mapfile.c_str());
	stream >> width >> height;
	int totCell = width * 2 + height * 2 - 4;
	for(int i = 0; i < totCell; i ++) {
	}
}
