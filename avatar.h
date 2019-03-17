/*
Illia Shershun
CS202 Spring

CLass that stores information about avatar: items in the bag(item list), history of playing, and information about the player(both personal and game info)
*/

#ifndef AVTR_H
#define AVTR_H

#include "itemList.h"
#include "history.h"
#include "characterInfo.h"

class Avatar
{
public:
	Avatar();
	Avatar(iList & inventory_, History & history_, Game & information_);
	Avatar(const Avatar & copyFrom);

	~Avatar();

	const Avatar & operator=(const Avatar & copyFrom);
	friend ostream & operator<<(ostream & out, const Avatar & toDisplay);
private:
	iList inventory;
	History history;
	Game information;
	
};

#endif
