#include "board.h"
#include "event.h"
#include "property.h"

#include <iostream>
#include <fstream>
using namespace std;

Board::Board() {}
Board::~Board() {}

Board::Board(const string &mapfile) : width(0), height(0) {
	loadMap(mapfile);
}

void Board::loadMap(const string &mapfile) {
	ifstream stream(mapfile.c_str());
	stream >> width >> height;
	string tmp;
	getline(stream, tmp);
	int totCell = width * 2 + height * 2 - 4;
	for(int i = 0; i < totCell; i ++) {
		string name, group;
		getline(stream, name);
		getline(stream, group);
		if(group == "NONE") cells.push_back(new Event(name, group));
		else cells.push_back(new Property(name, group));
		getline(stream, tmp);
		getline(stream, tmp);
		getline(stream, tmp);
		getline(stream, tmp);
	}
}

void Board::printAll() {
	cout << cells.size() << endl;
	for(int i = 0; i < cells.size(); i ++) {
		cells[i]->print();
		cout << "________" <<endl;
	}
}
