#include "textdisplay.h"

#include <iostream>
using namespace std;

TextDisplay::TextDisplay() {};
TextDisplay::~TextDisplay() {};

TextDisplay *TextDisplay::getInstance() {
   if(instance == NULL) instance = new TextDisplay;
   return instance;
}

void TextDisplay::addTag(string str) {
	str.resize(14);
	tags.push_back(str);
}

void TextDisplay::clean() { tags.clear(); }

void TextDisplay::printBoard(int w, int h) {
}
