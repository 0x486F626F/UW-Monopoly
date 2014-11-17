#include "cell.h"
#include <iostream>

using namespace std;
Cell::Cell() {}
Cell::Cell(string s) : name(s) {}
Cell::~Cell() {}
void Cell::print() {
	for(int i = 0; i < CELLHEIGHT; i ++)
		cout <<"|"<< textImage[i]<<"|" << endl;	
}
