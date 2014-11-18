#include <string>
#include "board.h"
using namespace std;

int main(int argc, char *argv[]) {
	string save;
	bool testing = false;
	for(int i = 1; i < argc; i ++)
		if(string(argv[i]) == "-load") save = argv[i + 1];
		else if(string(argv[i]) == "-testing") testing = true;
	Board *p = Board::getInstance(save, testing);
	p->startGame();
	return 0;
}
