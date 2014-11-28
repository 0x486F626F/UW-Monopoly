#include "human.h"

#include <iostream>
#include <string>
using namespace std;

Human::Human() {}
Human::~Human() {}

string	Human::getPropertyName() {return propertyName;}

int		Human::command(Player *p) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "next") return 0;
		if(cmd == "roll") return 1;
		if(cmd == "improve") {
			cin >> propertyName;
			cin >> cmd;
			if(cmd == "buy") return 2;
			if(cmd == "sell") return 3;
		}
		if(cmd == "mortgage") return 4;
		if(cmd == "unmortgage") return 5;
		if(cmd == "assets") return 6;
		if(cmd == "trade") return 7;
	}
	return -1;
}

int		Human::lackMoney(Player *p, const int m) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "bankrupt") return 0;
		if(cmd == "improve") {
			cin >> propertyName;
			cin >> cmd;
			if(cmd == "sell") return 1;
		}
		if(cmd == "mortgage") return 2;
		if(cmd == "assets") return 3;
		if(cmd == "trade") {
			return 4;
		}
	}
	return -1;
}

bool	Human::buyProperty(Cell *b, Player *p) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}

int		Human::unblock(Player *p, const int fee, const int itemID) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "r") return 0;
		if(cmd == "p") return 1;
		if(cmd == "i") return 2;
	}
	return -1;
}

int		Human::tuition(const int fee, const int rate, Player *p) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "a") return 0;
		if(cmd == "b") return 1;
	}
}

int		Human::prepaid(Player *p, Cell *c) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return 1;
		if(cmd == "n") return 0;
	}
}

bool	Human::tradeMM(Player* p1, Player* p2, const int m1, const int m2) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}

bool	Human::tradeMP(Player* p1, Player* p2, const int m1, Cell* c2) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}

bool	Human::tradePM(Player* p1, Player* p2, Cell* c1, const int m2) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}

bool	Human::tradePP(Player* p1, Player* p2, Cell* c1, Cell* c2) {
	while(1) {
		string cmd;
		cin >> cmd;
		if(cmd == "y") return true;
		if(cmd == "n") return false;
	}
	return -1;
}
