#include "player.h"
#include "cell.h"
#include "dice.h"

#include <iostream>

using namespace std;

Player::~Player() {}
Player::Player(const int i, const std::string &s) : ID(i), name(s), numDice(2) {
	dice = Dice::getInstance(numDice);
}

int Player::getID() { return ID; }
char Player::getInit() { return name[0]; }
string Player::getName() { return name; }
void Player::setCurrentCell(Cell *c) { currentCell = c; }
Cell *Player::getCurrentCell() { return currentCell; }
void Player::addProperty(Cell *c) { property.push_back(c); }
void Player::removeProperty(Cell *c) {
	for(vector <Cell*>::iterator i = property.begin(); i != property.end(); i ++)
		if((*i)->getID() == c->getID()) {
			property.erase(i);
			break;
		}
}

int Player::roll(const bool testing) {
	vector <int> v;
	if(testing) {
		int t;
		for(int i = 0; i < numDice; i ++) {
			cin >> t;
			v.push_back(t);
		}
		v = dice->roll(v);
	}
	else v = dice->roll();
	int cnt = 0;
	for(int i = 0; i < numDice; i ++)
		cnt += v[i];
	return cnt;
}
