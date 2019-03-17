/*
Illia Shershun
CS202 Spring

Class that implements itemList.h - class that stores information about items that player owns
*/

#include "itemList.h"

/*
Default iNode constructor
*/
iNode::iNode() : next(NULL)
{
}

/*
iNode constructor with a parameter
*/
iNode::iNode(Item & item_) : next(NULL)
{
	item = item_;
}

/*
iNode destructor: Item destructor -> String destructor
*/
iNode::~iNode()
{
}

/*
helper function to get item that node stores
*/
Item iNode::getItem()
{
	return this->item;
}

/*
Helper function to access next node
*/
iNode *& iNode::getNext()
{
	return this->next;
}

/*
Helper function to set next node
*/
void iNode::setNext(iNode * newNode)
{
	this->next = newNode;
}

/*
Outstream overload: displays item in the node (calls item outstream overload which display the data)
*/
ostream & operator<<(ostream & out, const iNode & toDisplay)
{
	out << toDisplay.item;
	return out;
}

/*
Default iList constructor
*/
iList::iList() : head(NULL)
{
}

/*
iList copy constructor
*/
iList::iList(const iList & copyFrom) : head(NULL)
{
}

/*
iList destructor
*/
iList::~iList()
{
	iNode * curr = head;
	
	while(curr)
	{
		curr = head->getNext();
		delete head;
		head = curr;
	}
}

/*
iList assignment overload:
1)Checks for self assignment
2)Else for each node in the passed list:
2a)Grabs the item and inserts it into current list (performs deep copy when "grabbing")
*/
const iList & iList::operator=(const iList & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{	
		Item temp;
		for(iNode * start = copyFrom.head; start != NULL; start = start->getNext())
		{
			temp = start->getItem();
			insert(temp);
		}
	}
	
	return *this;
}

/*
iList plus operator overload - used to simplify data addition to the list. Could be used instead of insert
*/
iList & iList::operator+(Item & toInsert)
{
	iNode * newNode = new iNode(toInsert);
	
	if(!head)
	{
		head = newNode;
		
	}
	else
	{
		newNode->setNext(head);
		head = newNode;
	}
}

/*
iList insert function : takes node as a parameter
*/
void iList::insert(iNode * newNode)
{
	if(!head)
        {
                head = newNode;
        }
        else
        {
                newNode->setNext(head);
                head = newNode;
        }
}

/*
iList insert function : takes Item as a parameter
*/
void iList::insert(Item & item)
{
	iNode * newNode = new iNode(item);
	
	if(!head)
		head = newNode;
	else
	{
		newNode->setNext(head);
		head = newNode;
	}
}

/*
iList outstream overload - displays list data : 
For each node calls node overload -> which in turn calls Item overload
*/
ostream & operator<<(ostream & out, const iList & toDisplay)
{	
	out << "\n------------------INVENTORY------------------" << endl;
	if(toDisplay.head == NULL)
		out << "You have no items in your inventory!" << endl;
	else
	{
		for(iNode * start = toDisplay.head; start != NULL; start = start->getNext())
			out << *start;
	}
	out << "---------------------------------------------" << endl;

	return out;
}
