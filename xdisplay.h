#ifndef __XDISPLAY_H__
#define __XDISPLAY_H__

#include <vector>

#include "window.h"

class XDisplay {
	private:
		Xwindow *xw;
	public:
		XDisplay(const int w, const int h);
		~XDisplay();

		void drawCell(std::vector < std::vector<int> > v);
};

#endif
