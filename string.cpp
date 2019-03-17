/*
Illia Shershun
CS202 Spring

class that implements string.h
*/

#include "string.h"

/*
Default String constructor. Creates "empty" data
*/
String::String() : data(NULL)
{
        int strlen = 0;
        data = new char[strlen + 1];
}

/*
String constructor with char parameter. Checks that data passed is not NULL, then deep-copies it. Else, creates "empty" data
*/
String::String(const char * data_) : data(NULL)
{
        if(data_ != NULL)
	{
		setData(data_);
	}
	else
		data = new char[1];
}

/*
String copy constructor. Check that data passed in the String object is not NULL, then deep-copies it. Otherwise, creates "empty" data.
*/
String::String(const String & copyFrom) : data(NULL)
{
	if(copyFrom.data != NULL)
		setData(copyFrom.data);
	else
		data = new char[1];
}

/*
Destructor
*/
String::~String()
{
        delete[] this->data;
}

/*
Helper function to set data to the passed data.
*/
void String::setData(const char * data_)
{
        if(this->data)
                delete[] this->data;

        this->data = new char[strlen(data_)+1];
        strcpy(this->data, data_);
}

/*
String assignment overload. 
*/
String & String::operator=(const String & copyFrom)
{
        delete[] data;

	data = new char[strlen(copyFrom.data)+1];
	strcpy(data, copyFrom.data);
        return *this;
}

/*
String less than overlaod. Returns bool true if this->data is smaller than passed data
*/
bool String::operator<(const String & toCompare)
{
	return strcmp(this->data, toCompare.data) < 0;
}

/*
String == overload. Returns true if this->data is the same as the passed data
*/
bool String::operator==(const String & toCompare)
{
	return (strcmp(this->data, toCompare.data) == 0);
}

/*
String instream overload. Allows direct read into the String in the program. 
*/
istream & operator>>(istream & in, String & toInput)
{
        char * input = new char[1000];

        in.get(input, 1000, '\n');
	in.ignore(100, '\n');

        toInput = input;
        delete[] input;
        return in;
}

/*
String outstream overlaod. Displays content of the data
*/
ostream & operator<<(ostream & out, const String & toDisplay)
{
        out << toDisplay.data << endl;
        return out;
}
