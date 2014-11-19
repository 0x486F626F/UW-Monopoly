#include "event.h"
#include <iostream>
using namespace std;

Event::Event(Cell &c) : theCell(c) {cout << c.getName() << "|" << theCell.getName() << endl;}
Event::~Event() { delete &theCell; }
