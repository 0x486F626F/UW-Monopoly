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

		
		std::string getName();   //get the name of the group
		int		getID();   //get ID of the group
		bool	isMonopoly();   //check if the group is monopolized
		void	addProperty(Property *p);   //add a property to the group
		bool	noImprovement();
};

#endif
