#include "group.h"
#include "property.h"

using namespace std;

Group::Group(const int i, const std::string &s) : ID(i), name(s) {}
Group::~Group() {}

int Group::getID() { return ID; }
std::string Group::getName() { return name; }

bool Group::isMonopoly() {
	for(int i = 1; i < properties.size(); i ++)
		if(properties[0]->getOwnerID() != properties[i]->getOwnerID()) return false;
	return true;
}

void Group::addProperty(Property *p) {
	properties.push_back(p);
	p->setGroup(this);
}
