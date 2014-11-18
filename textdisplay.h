#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <string>

class Cell;

class TextDisplay {
	private:
		std:: string top, bot, emp;

		void printHorizontal(const int w, const int l, const int r, const std::vector <Cell *> &cells);
		void printVertical(const int w, const int l, const int r, const std::vector <Cell *> &cells, const std::string central);
	public:
		TextDisplay();
		~TextDisplay();

		void printAll(const int w, const int h, const std::vector<Cell *> &cells);
};
#endif
