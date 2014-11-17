#include "cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {}
Cell::Cell(const string &s, const string &g) : name(s), group(g) {}
Cell::~Cell() {}
void Cell::print() {
	for(int i = 0; i < CELLHEIGHT; i ++)
		cout <<"|"<< textImage[i]<<"|" << endl;	
}
