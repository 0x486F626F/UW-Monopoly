#ifndef __XDISPLAY_H__
#define __XDISPLAY_H__

#include <vector>

#include "window.h"
#include "cell.h"

class XDisplay {
	private:
		Xwindow *xw;
	public:
		XDisplay(const int w, const int h);
		~XDisplay();

		void drawCell(Cell *c);
};

#endif
