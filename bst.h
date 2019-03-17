/*
Illia Shershun
CS202 Spring

Class that stores item list and information of each player
*/

#ifndef BST_H
#define BST_H

#include "itemList.h"
#include "characterInfo.h"

#include <iomanip>

class tNode
{
public:
	tNode();
	tNode(tNode *& copyFrom);
	tNode(iList & inventory_, Game & character_);

	~tNode();

	tNode *& getLeft();
	tNode *& getRight();
	void setLeft(tNode * newNode);
	void setRight(tNode * newNode);
	void copyNode(tNode *& copyFrom);

	String showNickName();
	Game getCharacter();
	iList getInventory();
	void showInventory();

	bool operator<(tNode & toCompare);
	friend ostream & operator<<(ostream & out, const tNode & toDisplay);
private:
	iList inventory;
	Game character;
	tNode * left;
	tNode * right;
};

class Tree
{
public:
	Tree();
	Tree(const Tree & copyFrom);

	~Tree();

	void insert(iList & inventory_, Game & character_);
	void displayTree();
	void flush();
	bool removePlayer(String & nickName_);
	bool displayPlayer(String & nickName_);
	void display();
private:
	tNode * root;

	void recursiveInsert(tNode *& curr_root, iList & inventory_, Game & character_);
	void flush(tNode *& curr_root);
	void displayTree(tNode * curr_root, int space);
	bool displayPlayer(tNode * curr_root, String & nickName_);
	void display(tNode * curr_root);
	bool removePlayer(tNode *& curr_root, String & nickName_);
	void deleteNode(tNode *& target);
	tNode * inOrder(tNode *& curr_root, tNode *& target);
	tNode * inOrderHelper(tNode *& curr_root, tNode *& target);
	tNode * leftMost(tNode * target);
	tNode * rightMost(tNode * target);
};

#endif
