#ifndef __EVENT_H__
#define __EVENT_H__

#include "cell.h"

class Event : public Cell {
	protected:
		Cell &c;
		Event(Cell &c);
		~Event();
};

#endif
