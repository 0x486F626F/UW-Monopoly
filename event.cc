#include "event.h"
#include <iostream>
using namespace std;

Event::Event(Cell &c) : theCell(c) {} 
Event::~Event() { delete &theCell; }
