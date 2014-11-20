#include "event.h"
#include <iostream>
using namespace std;

Event::Event(Cell &c) : theCell(c) {} 
Event::~Event() { delete &theCell; }

void Event::generateTextImage() { theCell.generateTextImage(); }
void Event::setCost(const int c) { theCell.setCost(c); } 
int Event::getCost() { return theCell.getCost(); }
void Event::setCostImprove(const int c) { theCell.setCostImprove(c); }
int Event::getCostImprove() { return theCell.getCostImprove(); }
void Event::addRent(const int r) { theCell.addRent(r); }
void Event::setOwner(Player *p) { theCell.setOwner(p); }
void Event::swapOwner(Player *p1, Player *p2) { theCell.swapOwner(p1, p2); }
Group *Event::getGroup() { return theCell.getGroup(); }
bool Event::isBuyable() { return theCell.isBuyable(); }
bool Event::isImproveable() { return theCell.isImproveable(); }

int Event::getID() { return theCell.getID(); }
string Event::getName() { return theCell.getName(); }
void Event::setXCoords(const int x, const int y) { theCell.setXCoords(x, y); }
void Event::addPlayer(Player *p) { theCell.addPlayer(p); }
void Event::removePlayer(Player *p) { theCell.removePlayer(p); }
void Event::movePlayer(Player *p) { theCell.movePlayer(p); }

vector <string> Event::getTextImage() { return theCell.getTextImage(); }


