#include "player.h"

using namespace std;

Player::Player() {}
Player::~Player() {}
Player::Player(string s) : name(s) {}

char Player::getInit() { return name[0]; }
void Player::setCurrentCell(Cell *c) { currentCell = c; }
void Player::addProperty(Cell *c) { property.push_back(c); }
string Player::getName() { return name; } 
