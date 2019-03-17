/*
Illia Shershun
CS202 Spring

Class that implements item.h
*/

#include "item.h"

/*
Default constructor
*/
Item::Item() : name(NULL), use(NULL)
{
}

/*
Constructor with parameters - uses String class assignment overload to copy data
*/
Item::Item(String & name_, String & use_) : name(NULL), use(NULL)
{
	name = name_;
	use = use_;
}

/*
Copy constructor - uses Item assignment overload to copy data
*/
Item::Item(const Item & copyFrom) : name(NULL), use(NULL)
{
	*this = copyFrom;
}

/*
Destructor - calls String destructor for the data (name and use)
*/
Item::~Item()
{
}

/*
Function to set the name (uses passed parameter)
*/
void Item::setName(String & name_)
{
	name = name_;
}

/*
Function to set the use (uses passed parameter)
*/
void Item::setUse(String & use_)
{
	use = use_;
}

/*
Item assignment overload - uses String class assignment overload to copy data (name and use)
*/
Item & Item::operator=(const Item & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		name = copyFrom.name;
		use = copyFrom.use;
	}

	return *this;
}

/*
Oustream overload - displays information about the item
*/
ostream & operator<<(ostream & out, const Item & toDisplay)
{
	out << "Name: " << toDisplay.name << "Use: " << toDisplay.use << endl;
	return out;
}
