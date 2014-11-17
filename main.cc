#include "property.h"
#include "cell.h"
#include "event.h"
#include <iostream>

using namespace std;

int main() {
	Cell *p = new Property("ABCDEFGHIJK");
	p->print();
	Cell *q = new Event("ABCDEFGHIJK");
	q->print();
}
