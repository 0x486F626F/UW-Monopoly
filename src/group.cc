#include "group.h"
#include "property.h"
#include "player.h"

using namespace std;


//constructor and destructor
Group::Group(const int i, const std::string &s) : ID(i), name(s) {}
Group::~Group() {}

int		Group::getID() { return ID; }
std::string Group::getName() { return name; }

bool	Group::isMonopoly() {
	for(int i = 0; i < properties.size(); i ++)
		if(!properties[i]->isSold()) return false;
	for(int i = 1; i < properties.size(); i ++)
		if(properties[0]->getOwner()->getID() != properties[i]->getOwner()->getID()) return false;
	return true;
}

bool	Group::noImprovement() {
	for(int i = 0; i < properties.size(); i ++)
		if(properties[i]->getLevel() > 0) return false;
	return true;
}

void	Group::addProperty(Property *p) {
	properties.push_back(p);
	p->setGroup(this);
}
