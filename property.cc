#include "property.h"
#include "player.h"

using namespace std;

Property::Property() {}

Property::Property(const int i, const std::string &s) : Cell(i, s) {
	sold = false;
	mortgaged = false;
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

int Property::getCost() { return cost; }
void Property::setCost(const int c) { cost = c; }
int Property::getCostImprove() { return costImprove; }
void Property::setCostImprove(const int c) { costImprove = c; } 
int Property::getLevel() { return level; }
void Property::setLevel(const int l) { level = l; }
int		Property::getMaxLevel() { return rents.size() - 1; }
void Property::setOwner(Player *p) {
	if(p == NULL) sold = false;
	else sold = true;
	owner = p;
}
Player *Property::getOwner() { return owner; }
Group *Property::getGroup() { return group; }
void Property::setGroup(Group *g) { group = g; }
void Property::addRent(const int r) { rents.push_back(r); }
int Property::getRent(const int l) { return rents[l]; }
bool Property::isSold() { return sold; }
bool Property::isMortgaged() { return mortgaged; }
void Property::mortgage() {
	mortgaged = true;
	//owner->addMoney(cost);
}
void Property::unmortgage() {
	mortgaged = false;
}
bool Property::canBuy() { return !sold; }
bool Property::canImprove() { return rents.size() > 1; }
