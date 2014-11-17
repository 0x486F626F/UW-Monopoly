#include <iostream>

#include "board.h"

using namespace std;

int main() {
	Board *p = new Board("uw.map");
	p->printAll();
}
