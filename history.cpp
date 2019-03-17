/*
Illia Shershun
CS202 Spring

Class that implements history.h
*/

#include "history.h"

/*
Default constructor
*/
History::History() : awards(0), hoursPlayed(0.0)
{
}

/*
Constructor with parameters
*/
History::History(int awards_, double hoursPlayed_) : awards(0), hoursPlayed(0.0)
{
	awards = awards_;
	hoursPlayed = hoursPlayed_;
}

/*
Assignment overload. Not really needed, but might be useful
*/
History & History::operator=(const History & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		awards = copyFrom.awards;
		hoursPlayed = copyFrom.hoursPlayed;
	}

	return *this;
}

/*
Oustream overlod - display history information
*/
ostream & operator<<(ostream & out, const History & toDisplay)
{
	out << "\nNumber of awards: " << toDisplay.awards << "\nHours Played: " << toDisplay.hoursPlayed << endl;
	return out;
}
