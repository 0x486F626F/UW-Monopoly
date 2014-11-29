#include "showmsg.h"
#include "behavior.h"
#include <iostream>
using namespace std;

ShowMsg::ShowMsg(Cell &c, const string &m) : Event(c), msg(m) {};
ShowMsg::~ShowMsg() {}

void ShowMsg::event(Player *p) {
	theCell.event(p);
	cout << msg << endl;
}
