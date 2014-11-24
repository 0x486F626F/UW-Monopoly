#ifndef __GROUP_H__
#define __GROUP_H__

#include <vector>
#include <string>

class Property;

class Group {
	private:
		int ID;
		std::string name;
		std::vector <Property*> properties;
	public:
		Group(const int i, const std::string &s);
		~Group();

		//get the name of the group
		std::string getName();
		//get ID of the group
		int getID();
		//check if the group is monopolized
		bool isMonopoly();
		//add a property to the group
		void addProperty(Property *p);
		bool	noImprovement();
};

#endif
