#include "xdisplay.h"
#include "window.h"
#include "cell.h"

using namespace std;

XDisplay::XDisplay(const int w, const int h) {
	xw = new Xwindow(w * 100, h * 100);
}

XDisplay::~XDisplay() { delete xw; }

void XDisplay::drawCell(Cell *c) {
}

