#include "dice.h"

using namespace std;

Dice::Dice(const int v) : n(v) {}
Dice::~Dice() {}
vector <int> Dice::roll() {
	vector <int> v;
	for(int i = 0; i < n; i ++)
		v.push_back(rand() % DICEMAX + 1);
	return v;
}
vector <int> Dice::roll(vector <int> &a) {
	vector <int> v;
	for(int i = 0; i < n; i ++)
		v.push_back(a[i]);
	return v;
}

void Dice::cleanInstance() { delete instance; }

Dice *Dice::getInstance(const int v) {
	if(!instance) {
		instance = new Dice(v);
		atexit(cleanInstance);
	}
	return instance;
}

Dice *Dice::instance = NULL;
