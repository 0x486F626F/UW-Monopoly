#ifndef __EVENT_H__
#define __EVENT_H__

#include "cell.h"

class Event : public Cell {
	protected:
		Cell &theCell;
		Event(Cell &c);
		~Event();
};

#endif
