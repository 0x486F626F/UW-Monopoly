#ifndef __PROPERTY_H__
#define __PROPERTY_H__
#include <string>
#include "cell.h"

class Property : public Cell {
	private:
		void generateTextImage();
	public:
		Property();	
		Property(std::string s);
};
#endif
