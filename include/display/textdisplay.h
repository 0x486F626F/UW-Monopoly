#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <string>

class Cell;

class TextDisplay {
	private:
		std:: string top, bot, emp;
      
		void printHorizontal(const int w, const int l, const int r, const std::vector <Cell *> &cells);   //print horizontal/vertical component of the map
		void printVertical(const int w, const int l, const int r, const std::vector <Cell *> &cells, const std::string central);
	public:
		TextDisplay();
		~TextDisplay();
      
      
		void printAll(const int w, const int h, const std::vector<Cell *> &cells);   //combine printHorizontal/printVertial to give the full map
};
#endif
