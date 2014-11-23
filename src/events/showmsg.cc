#include "showmsg.h"
#include "behavior.h"

using namespace std;

ShowMsg::ShowMsg(Cell &c, const string &m) : Event(c), msg(m) {};
ShowMsg::~ShowMsg() {}

void ShowMsg::event(Player *p) {
	theCell.event(p);
	bh->printMsg(msg);
}
