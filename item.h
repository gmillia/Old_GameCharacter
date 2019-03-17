/*
Illia Shershun
CS202 Spring

Class for an item: each character in the game might possess an item, be it a simple product, tool, or clothes. Thus, each item has a name (potato, hammer, gray cap, etc), and specific use (can be eaten, worn, used as a duel weapon, etc)
*/

#ifndef ITM_H
#define ITM_H

#include "string.h"

class Item
{
public:
	Item();
	Item(String & name_, String & use_);
	Item(const Item & copyFrom);

	~Item();

	void setName(String & name_);
	void setUse(String & use_);

	Item & operator=(const Item & copyFrom);
	friend ostream & operator<<(ostream & out, const Item & toDisplay);
private:
	String name;
	String use;
};

#endif
