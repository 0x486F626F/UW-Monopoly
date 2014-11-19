#include "event.h"

Event::Event(Cell &c) : c(c) {}
Event::~Event() { delete &c; }
