#include "facility.h"
#include "player.h"

using namespace std;

//constructor and destructor
Facility::Facility() {}
Facility::Facility(const int i, const std::string &s) : Cell(i, s) {}

void Facility::generateTextImage() {
	textImage.clear();
	string tmp = name;
	tmp.resize(CELLWIDTH * (CELLHEIGHT - 1), ' ');
	for(int i = 0; i < (CELLHEIGHT - 1); i ++) {
		string t;
		for(int j = 0; j < CELLWIDTH; j ++)
			t += tmp[i * CELLWIDTH + j];
		textImage.push_back(t);
	}
	tmp = "";
	for(int i = 0; i < currentPlayer.size(); i ++)
		tmp += currentPlayer[i]->getInit();
	tmp.resize(CELLWIDTH, ' ');
	textImage.push_back(tmp);
}

void Facility::setCost(const int c) {}

void Facility::setCostImprove(const int c) {}

void Facility::addRent(const int r) {}

void Facility::setOwner(Player *p) {}

void Facility::swapOwner(Player *p1, Player *p2) {}

bool Facility::isBuyable() { return false; }

bool Facility::isImproveable() { return false; }

Group* Facility::getGroup() { return NULL; }

void Facility::event(Player *p) {}
