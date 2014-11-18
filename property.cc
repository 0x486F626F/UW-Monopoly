#include "property.h"

using namespace std;

void Property::generateTextImage() {
	textImage.clear();
	string tmp;
	if(sold) tmp = owner->getInit();
	tmp.resize(CELLWIDTH, ' ');
	textImage.push_back(tmp);
	tmp = "";
	tmp.resize(CELLWIDTH, '-');
	textImage.push_back(tmp);

	tmp = name;
	tmp.resize(CELLWIDTH * (CELLHEIGHT - 3), ' ');
	for(int i = 0; i < (CELLHEIGHT - 3); i ++) {
		string t;
		for(int j = 0; j < CELLWIDTH; j ++)
			t += tmp[i * CELLWIDTH + j];
		textImage.push_back(t);
	}

	tmp = "";
	for(int i = 0; i < currentPlayer.size(); i ++)
		tmp += currentPlayer[i]->getInit();
	tmp.resize(CELLWIDTH, ' ' );
	textImage.push_back(tmp);
}

Property::Property() {}
Property::Property(const string &s, const string &g) : Cell(s, g), sold(0), mortgaged(0) {
	generateTextImage();
}

void Property::setCost(const int c) { cost = c; }
void Property::setCostImprove(const int c) { costImprove = c; }
void Property::addRent(const int r) { rents.push_back(r); }

void Property::setOwner(Player *p) {
	sold = true;
	p->addProperty(this);
	owner = p;
	generateTextImage();
}
