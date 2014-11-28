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
	bankrupted = false;
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
Cell*	Player::getFirstProperty() {return property.size() == 0 ? NULL : property[0]; }
Cell*	Player::findProperty(const string &s) {
   //find if the player owns a certain property, yes than return a pointer to that cell, otherwise return NULL
	for(vector <Cell*>::iterator i = property.begin(); i != property.end(); i ++)
		if((*i)->getName() == s) return *i;
	return NULL;
}

int		Player::getMoney() { return money; }
void	Player::setMoney(const int m) { money = m; }
void	Player::addMoney(const int m) { money += m; }
int		Player::cntProperty() {
	int cnt = money;
	for(int i = 0; i < property.size(); i ++)
		if(!property[i]->isMortgaged())
			cnt += property[i]->getCost();
	return cnt;
}

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
bool	Player::isBankrupted() { return bankrupted; }
void	Player::setBankrupted(const bool b) { bankrupted = b; }
void	Player::addItem(const int idItem) {item.push_back(idItem);}
bool	Player::removeItem(const int idItem) {
	for(std::vector<int>::iterator i = item.begin(); i != item.end(); i ++)
		if((*i) == idItem) {
			item.erase(i);
			return true;
		}
	return false;
}

void Player::printAssets() {
	cout << "Name:		" << name << endl;
	cout << "Money:		" << money << endl;
	cout << "Total Assets:	" << cntProperty() << endl;
	cout << "Properties:	" << property.size() << endl;
	for(int i = 0; i < property.size(); i ++)
		cout << property[i]->getID() << "	" << property[i]->getName() << "	" << property[i]->getCost() << endl;
}
