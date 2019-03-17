/*
llia Shershun
CS202 Spring

Creating string class which will be used instead of char *
*/

#ifndef STRNG_H
#define STRNG_H

#include <cstring>
#include <iostream>

using namespace std;

class String
{
public:
        String();
        String(const char * data_);
	String(const String & copyFrom);

        ~String();

        void setData(const char * data_);

        String & operator=(const String & copyFrom);
	bool operator<(const String & toCompare);
	bool operator==(const String & toCompare);
        friend ostream & operator<<(ostream & out, const String & toDisplay);
        friend istream & operator>>(istream & in, String & toInput);
private:
        char * data;
};

#endif
