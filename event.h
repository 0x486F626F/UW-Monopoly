#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>
#include "cell.h"

class Event : public Cell {
	private:
		void generateTextImage();
	public:
		Event();
		Event(std::string s);
};
#endif
