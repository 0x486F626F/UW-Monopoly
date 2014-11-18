#include "board.h"
#include "event.h"
#include "property.h"

#include <iostream>
#include <fstream>
#include <sstream>
using namespace std;

Board::Board() {}
Board::~Board() {}

Board::Board(const string &mapfile) : width(0), height(0) {
	td = new TextDisplay;
	loadMap(mapfile);
}

void Board::loadMap(const string &mapfile) {
	string tmp;
	ifstream stream(mapfile.c_str());
	getline(stream, tmp);
	istringstream str(tmp);
	str >> width >> height;
	int totCell = width * 2 + height * 2 - 4;
	for(int i = 0; i < totCell; i ++) {
		string name, group;
		getline(stream, name);
		getline(stream, group);

		Cell *p;
		if(group == "NONE") p = new Event(name, group);
		else p = new Property(name, group);

		int cost, n, rent;
		stream >> cost;
		if(cost) {
			stream >> cost >> rent;
			p->setCost(cost);
			p->addRent(rent);
		}
		else p->setCost(0x3f3f3f3f);


		stream >> cost;
		if(cost) {
			stream >> cost >> n;
			p->setCostImprove(cost);
			while(n --) {
				stream >> rent;
				p->addRent(rent);
			}
		}
		else p->setCostImprove(0x3f3f3f3f);

		stream >> n;
		for(int i = 0; i < n; i ++) {
		}
		cells.push_back(p);

		getline(stream, tmp);
		getline(stream, tmp);
	}
}

void Board::setPlayer(Player *p, Cell *c) { c->addPlayer(p); }

void Board::printAll() {
	Player *p1 = new Player("Hobo");
	Player *p2 = new Player("Alex");
	setPlayer(p1, cells[1]);
	setPlayer(p2, cells[1]);
	td->printAll(width, height, cells);
}
