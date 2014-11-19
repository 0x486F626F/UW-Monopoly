#include "sellproperty.h"
#include <iostream>

using namespace std;

SellProperty::SellProperty(Cell &c) : Event(c) {cout << c.getName() << "||" << theCell.getName() << endl;}
SellProperty::~SellProperty() {}

void SellProperty::generateTextImage() { theCell.generateTextImage(); }
void SellProperty::setCost(const int c) { theCell.setCost(c); } 
void SellProperty::setCostImprove(const int c) { theCell.setCostImprove(c); }
void SellProperty::addRent(const int r) { theCell.addRent(r); }
void SellProperty::setOwner(Player *p) { theCell.setOwner(p); }
void SellProperty::swapOwner(Player *p1, Player *p2) { theCell.swapOwner(p1, p2); }
Group *SellProperty::getGroup() { return theCell.getGroup(); }
bool SellProperty::isBuyable() { return theCell.isBuyable(); }
bool SellProperty::isImproveable() { return theCell.isImproveable(); }

int SellProperty::getID() { return theCell.getID(); }
string SellProperty::getName() { return theCell.getName(); }
void SellProperty::setXCoords(const int x, const int y) { theCell.setXCoords(x, y); }
void SellProperty::addPlayer(Player *p) { theCell.addPlayer(p); }
void SellProperty::removePlayer(Player *p) { theCell.removePlayer(p); }
void SellProperty::movePlayer(Player *p) { theCell.movePlayer(p); }

vector <string> SellProperty::getTextImage() { return theCell.getTextImage(); }

void SellProperty::event(Player *p) {
	theCell.event(p);
	if(isBuyable()) {
		cout << "Do you want to buy " << theCell.getName() << endl;
	}
}
