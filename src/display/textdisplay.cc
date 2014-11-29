#include "textdisplay.h"
#include "cell.h"

#include <iostream>
#include <vector>
#include <string>
using namespace std;

//constructor and destructor
TextDisplay::TextDisplay() {};
TextDisplay::~TextDisplay() {};

void TextDisplay::printHorizontal(const int w, const int l, const int r, const std::vector <Cell *> &cells) {
	for(int j = 0; j < CELLHEIGHT; j ++) {
		for(int i = l; i != r; i += l < r ? 1 : -1) {
			cout << "|" << cells[i]->getTextImage()[j];
		}
		cout << "|" << endl;
	}
	for(int i = 0; i < w; i ++)
		cout << bot;
	cout << "|" << endl;
}

void TextDisplay::printVertical(const int w, const int l, const int r, const std::vector<Cell *> &cells, const string central) {
	for(int j = 0; j < CELLHEIGHT; j ++) {
		cout << "|" << cells[l]->getTextImage()[j] << "|";
		for(int i = 0; i < w - 3; i ++)
			cout << emp << " ";
		cout << emp;
		cout << "|" << cells[r]->getTextImage()[j] << "|";
		cout << endl;
	}
	cout << bot << "|";
	for(int i = 0; i < w - 3; i ++)
		cout << central << central[0];
	cout << central;
	cout << bot << "|";
	cout << endl;
}

void TextDisplay::printAll(const int w, const int h, const std::vector <Cell *> &cells) {
	top = "_";
	top.resize(CELLWIDTH + 1, '_');
	bot = "|";
	bot.resize(CELLWIDTH + 1, '_');
	emp = " ";
	emp.resize(CELLWIDTH, ' ');

	for(int i = 0; i < w; i ++)
		cout << top;
	cout << "_" << endl;

	printHorizontal(w, w + h - 2, w + h + w - 2, cells);

	string tmp = top;
	tmp.resize(CELLWIDTH);
	for(int i = 1; i < h - 1; i ++)
		if(i != h - 2) printVertical(w, w + h - 2 - i, w * 2 + h - 3 + i, cells, emp);
		else printVertical(w, w + h - 2 - i, w * 2 + h - 3 + i, cells, tmp);

	printHorizontal(w, w - 1, -1, cells);
}
