/*
Illia Shershun
CS202 Spring

Class taht stores all the items that player owns
*/

#ifndef ILST_H
#define ILST_H

#include "item.h"

class iNode
{
public:
	iNode();
	iNode(Item & item_);

	~iNode();

	Item getItem();

	iNode *& getNext();
	void setNext(iNode * newNode);

	friend ostream & operator<<(ostream & out, const iNode & toDisplay);
private:
	Item item;
	iNode * next;
};

class iList
{
public:
	iList();
	iList(const iList & copyFrom);

	~iList();

	void insert(Item & item);

	const iList & operator=(const iList & copyFrom);
	iList & operator+(Item & toInsert);
	friend ostream & operator<<(ostream & out, const iList & toDisplay);
private:
	iNode * head;

	void insert(iNode * newNode);
};

#endif
