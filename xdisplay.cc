#include "xdisplay.h"

using namespace std;

XDisplay::XDisplay(const int w, const int h) {
	xw = new Xwindow(w * 100, h * 100);
}

XDisplay::~XDisplay() { delete xw; }

void XDisplay::drawCell(std::vector < vector <int> > v) {
	for(int i = 0; i < v.size(); i ++)
		xw->fillRectangle(v[i][0], v[i][1], v[i][2], v[i][3], v[i][4]);
}

