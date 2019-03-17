/*
Illia Shershun
CS202 Spring

Class that implements Visual.h
*/

#include "visual.h"

/*
Default Visual constructor
*/
Visual::Visual() : height(0.0)
{
}

/*
Visual constructor with parameters
*/
Visual::Visual(String & gender_, String & bodyType_, double height_) : height(0.0)
{
	gender = gender_;
	bodyType = bodyType_;
	height = height_;
}

/*
Visual copy constructor
*/
Visual::Visual(const Visual & copyFrom) : height(0.0)
{
	gender = copyFrom.gender;
	bodyType = copyFrom.bodyType;
	height = copyFrom.height;
}

/*
Visual destructor
*/
Visual::~Visual()
{
}

/*
Visual assignment overlaod
*/
Visual & Visual::operator=(const Visual & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		gender = copyFrom.gender;
		bodyType = copyFrom.bodyType;
		height = copyFrom.height;
	}
	
	return *this;
}

/*
Visual outstream overlaod
*/
ostream & operator<<(ostream & out, const Visual & toDisplay)
{
	out << "\nGender: " << toDisplay.gender << "\nBody Type: " << toDisplay.bodyType << "\nHeight: " << toDisplay.height << endl;
	return out;
}
