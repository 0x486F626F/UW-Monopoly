#include "player.h"
#include "cell.h"
#include "dice.h"
#include "human.h"

#include <iostream>

using namespace std;

//constructor and destructor
Player::~Player() {
	delete stg;
}
Player::Player(const int i, const std::string &s) : ID(i), name(s), numDice(2) {
	block = rest = 0;
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

int Player::getMoney() { return money; }
void Player::setMoney(const int m) { money = m; }
void Player::addMoney(const int m) { money += m; }

void	Player::setStrategy(const int type) { 
	if(type == 0) stg = new Human;
}
Strategy*	Player::getStrategy() { return stg; }

int		Player::getLeftRoll() { return leftRoll; }
void	Player::setLeftRoll(const int r) { leftRoll = r; }
int		Player::getRest() { return rest; }
void	Player::setRest(const int r) { rest = r; }
int		Player::getBlock() { return block; }
void	Player::setBlock(const int b) { block = b; }

void Player::printInfo() {
	cout << name << " " << money << endl;
	cout << getRest() << " " << getBlock() << endl;
	cout << property.size() << endl;
	for(int i = 0; i < property.size(); i ++)
		cout << property[i]->getID() << " " << property[i]->getName() << endl;
}
