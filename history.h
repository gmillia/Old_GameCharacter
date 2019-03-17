/*
Illia Shershun
CS202 Spring

Class for the history of the player (simplified version). Includes - number of awards and hours played
*/

#ifndef HSTR_H
#define HSTR_H

#include <iostream>

using namespace std;

class History
{
public:
	History();
	History(int awards_, double hoursPlayed_);

	History & operator=(const History & copyFrom);
	friend ostream & operator<<(ostream & out, const History & toDisplay);
private:
	int awards;
	double hoursPlayed;
};

#endif
