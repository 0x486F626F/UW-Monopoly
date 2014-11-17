#include "event.h"

using namespace std;

void Event::generateTextImage() {
	string tmp = name;
	tmp.resize(CELLWIDTH * (CELLHEIGHT - 1), ' ');
	for(int i = 0; i < (CELLHEIGHT - 1); i ++) {
		string t;
		for(int j = 0; j < CELLWIDTH; j ++)
			t += tmp[i * CELLWIDTH + j];
		textImage.push_back(t);
	}

	tmp = "";
	for(int i = 0; i < currentPlayer.size(); i ++)
		tmp += currentPlayer[i]->getInit();
	tmp.resize(CELLWIDTH, ' ');
	textImage.push_back(tmp);
}

Event::Event() {}
Event::Event(const string &s, const string &g) : Cell(s, g) {
	generateTextImage();
}
