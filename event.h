#ifndef __EVENT_H__
#define __EVENT_H__
#include <string>
#include "cell.h"

class Event : public Cell {
	private:
		void generateTextImage();
	public:
		Event();
		Event(const std::string &s, const std::string &g);
};
#endif
