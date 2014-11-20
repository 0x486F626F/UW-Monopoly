#include "property.h"
#include "player.h"

using namespace std;

Property::Property() {}

Property::Property(const int i, const std::string &s) : Cell(i, s) {
	sold = false;
	mortgaged;
}

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

void Property::setCost(const int c) { cost = c; buyable = true; }
void Property::setCostImprove(const int c) { costImprove = c; improveable = true; } 
void Property::addRent(const int r) { rents.push_back(r); }
void Property::setOwner(Player *p) {
	sold = true;
	p->addProperty(this);
	owner = p;
}
Player *Property::getOwner() { return owner; }
void Property::swapOwner(Player *p1, Player *p2) {
	p1->removeProperty(this);
	p2->addProperty(this);
	owner = p2;
}

bool Property::isBuyable() { return buyable && !sold; }
bool Property::isImproveable() { return improveable && level < rents.size() - 1; }

int Property::getOwnerID() { return owner->getID(); }
void Property::setGroup(Group *g) { group = g; }
Group *Property::getGroup() { return group; }

int Property::getCost() { return cost; }
int Property::getCostImprove() { return costImprove; }

void Property::event(Player *p) {
}


