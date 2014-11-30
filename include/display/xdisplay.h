#ifndef __XDISPLAY_H__
#define __XDISPLAY_H__
#include <vector>
class Xwindow;
class Property;
class Facility;

class XDisplay {
	private:
		static XDisplay* instance;
		int width, height;
		Xwindow *xw;

		XDisplay(const int w, const int h);
		~XDisplay();
		static void cleanInstance();
	public:
		static XDisplay* getInstance();	
		static XDisplay* getInstance(const int w, const int h);	

		void drawCell(Property *c);
		void drawCell(Facility *c);
		void drawLogo();
		void drawDice(const std::vector <int> &d);
};

#endif
