/*
Illia Shershun
CS202 Spring

Class that stores info about visual aspect of the players character in the game. This is simplified version, so information stored is only gender (like in real world you can make up +100500 genders), height, and character type.
*/

#ifndef VSL_H
#define VSL_H

#include "string.h"

class Visual
{
public:
	Visual();
	Visual(String & gender_, String & bodyType_, double height_);
	Visual(const Visual & copyFrom);

	~Visual();

	Visual & operator=(const Visual & copyFrom);
	friend ostream & operator<<(ostream & out, const Visual & toDisplay);
private:
	String gender;
	String bodyType;
	double height;
};

#endif
