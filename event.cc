#include "event.h"

Event::Event(Cell &c) : theCell(c) {}
Event::~Event() { delete &theCell; }
