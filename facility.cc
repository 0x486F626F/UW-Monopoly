#include "facility.h"
#include "player.h"

using namespace std;

Facility::Facility() {}
Facility::Facility(const int i, const std::string &s) : Cell(i, s) {}

void Facility::generateTextImage() {
	textImage.clear();
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
