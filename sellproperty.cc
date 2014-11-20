#include "sellproperty.h"
#include "player.h"
#include <iostream>

using namespace std;

//constructor and destructor
SellProperty::SellProperty(Cell &c) : Event(c) {} 
SellProperty::~SellProperty() {}

void SellProperty::generateTextImage() { theCell.generateTextImage(); }
void SellProperty::setCost(const int c) { theCell.setCost(c); } 
int SellProperty::getCost() { return theCell.getCost(); }
void SellProperty::setCostImprove(const int c) { theCell.setCostImprove(c); }
int SellProperty::getCostImprove() { return theCell.getCostImprove(); }
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
	if(isBuyable() && p->getMoney() > getCost()) {
		while(1) {
			cout << "Do you want to buy " << theCell.getName() << "? (y/n)" << endl;
			string response;
			cin >> response;
			if(response == "y") {
				p->addMoney(-getCost());
				setOwner(p);
				break;
			}
			else if(response == "n") break;
		}
	}
}
