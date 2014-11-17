#include "property.h"
#include "cell.h"
#include "event.h"
#include <iostream>

using namespace std;

int main() {
	Cell *p = new Property("ABCDEFGHIJK", "A");
	p->print();
	Cell *q = new Event("ABCDEFGHIJK", "B");
	q->print();
}
