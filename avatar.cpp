/*
Illia Shershun
CS202 Spring

Class that implements avatar.h - stores complete information about each player (character/avatar) in the game. 
*/

#include "avatar.h"

/*
Default constructor
*/
Avatar::Avatar()
{
}

/*
Constructor with parameters
*/
Avatar::Avatar(iList & inventory_, History & history_, Game & information_)
{
	inventory = inventory_;
	history = history_;
	information = information_;
}

/*
Copy Constructor
*/
Avatar::Avatar(const Avatar & copyFrom)
{
	inventory = copyFrom.inventory;
	history = copyFrom.history;
	information = copyFrom.information;
}

/*
Destructor - calss String class destructor
*/
Avatar::~Avatar()
{
}

/*
Assignment overload
*/
const Avatar & Avatar::operator=(const Avatar & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		inventory = copyFrom.inventory;
		history = copyFrom.history;
		information = copyFrom.information;
	}

	return *this;
}

/*
Outstream overload
*/
ostream & operator<<(ostream & out, const Avatar & toDisplay)
{
	out << toDisplay.inventory;
	out << toDisplay.history;
	out << toDisplay.information;
	return out;
}
