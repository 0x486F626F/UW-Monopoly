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

		std::string getName();
		int getID();
		bool isMonopoly();
		void addProperty(Property *p);
};

#endif
