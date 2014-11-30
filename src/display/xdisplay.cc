#include "xdisplay.h"
#include "property.h"
#include "facility.h"
#include "window.h"
#include <cstdlib>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
const int XCELLWIDTH = 50;
const int XCELLHEIGHT = 50;
const int MAXCHAR = 8;

XDisplay::XDisplay(const int w, const int h) : width(w), height(h), xw(new Xwindow(w * XCELLWIDTH, h * XCELLHEIGHT)) {}
XDisplay::~XDisplay() {delete xw;}
XDisplay*	XDisplay::instance = NULL;
XDisplay*	XDisplay::getInstance() {return instance;}
XDisplay*	XDisplay::getInstance(const int w, const int h) {
	if(!instance) {
		instance = new XDisplay(w, h);
		atexit(cleanInstance);
	}
	return instance;
}
void	XDisplay::cleanInstance() {delete instance;}

void XDisplay::drawCell(Property *c) {
	int x = c->getX();
	int y = c->getY();
	xw->fillRectangle(x, y, XCELLWIDTH, XCELLHEIGHT, 6);
	xw->fillRectangle(x, y, 1, XCELLHEIGHT, 1);
	xw->fillRectangle(x, y, XCELLWIDTH, 1, 1);
	//xw->fillRectangle(x, y + 10, XCELLWIDTH, 1, 1);
	xw->fillRectangle(x + XCELLWIDTH, y, 1, XCELLHEIGHT, 1);
	xw->fillRectangle(x, y + XCELLHEIGHT, XCELLWIDTH, 1, 1);
	vector <string> textImage = c->getTextImage();
	for(int i = 0; i < textImage.size(); i ++)
		xw->drawString(x + 5, y + 10 + i * 10, textImage[i], 1);
}

void XDisplay::drawCell(Facility *c) {
	int x = c->getX();
	int y = c->getY();
	xw->fillRectangle(x, y, XCELLWIDTH, XCELLHEIGHT, 3);
	xw->fillRectangle(x, y, 1, XCELLHEIGHT, 1);
	xw->fillRectangle(x, y, XCELLWIDTH, 1, 1);
	xw->fillRectangle(x + XCELLWIDTH, y, 1, XCELLHEIGHT, 1);
	xw->fillRectangle(x, y + XCELLHEIGHT, XCELLWIDTH, 1, 1);
	vector <string> textImage = c->getTextImage();
	for(int i = 0; i < textImage.size(); i ++)
		xw->drawString(x + 5, y + 10 + i * 10, textImage[i], 1);
}

void XDisplay::drawLogo() {
	xw->drawBigString(100, height * XCELLHEIGHT / 2 + 20, "Building Buyer 7000", 1);
	xw->drawBigString(100, height * XCELLHEIGHT / 2 - 20, "CS 246", 1);
	xw->drawString(350, height * XCELLHEIGHT / 2 + 40, "By h356zhan q26hu");
}

void XDisplay::drawDice(const vector<int> &d) {
	string tmp = "";
	for(int i = 0; i < d.size(); i ++) {
		cout << d[i] << endl;
		tmp += " " + char('0' + d[i]);
	}
	cout << tmp << endl;
	xw->drawBigString(200, 150, tmp, 1);
}
