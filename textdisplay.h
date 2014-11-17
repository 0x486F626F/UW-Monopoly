#ifndef __TEXTDISPLAY_H__
#define __TEXTDISPLAY_H__
#include <vector>
#include <string>
class TextDisplay {
	private:
		static TextDisplay *instance;

		std::vector <std::string> tags;
		int width, height
	public:
		static TextDisplay *getInstance();
		TextDisplay();
		~TextDisplay();
		void addTag(std::string str);
		void clean();
		void printBoard(int w, int h);
};
#endif
