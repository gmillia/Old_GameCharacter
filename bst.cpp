/*
Illia Shershun
CS202 Spring

Class that implements bst.h
*/

#include "bst.h"

/*
tNode default constructor
*/
tNode::tNode() : left(NULL), right(NULL)
{
}

/*
tNode copyConstructor : uses iList and Game assignment overloads to perform deep copy
*/
tNode::tNode(tNode *& copyFrom) : left(NULL), right(NULL)
{
	inventory = copyFrom->inventory;
	character = copyFrom->character;
}

/*
tNode constructor with arguments : uses iList and Game assignment overlaods to perform deep-copy.
*/
tNode::tNode(iList & inventory_, Game & character_) : left(NULL), right(NULL)
{
	inventory = inventory_;
	character = character_;
}

/*
tNode destructor
*/
tNode::~tNode()
{
	if(left)
		delete left;
	if(right)
		delete right;
}

/*
Function that returns left pointer (left node this node points to)
*/
tNode *& tNode::getLeft()
{
	return this->left;
}

/*
Function that return right pointer (right node this node points to)
*/
tNode *& tNode::getRight()
{
	return this->right;
}

/*
Helper function that sets left to the passed node
*/
void tNode::setLeft(tNode * newNode)
{
	this->left = newNode;
}

/*
Helper function that sets right to the passed node
*/
void tNode::setRight(tNode * newNode)
{
	this->right = newNode;
}

/*
tNode less than operator overload : returns true if this node < passed node:
1)Compares nicknames through String less than overload
*/
bool tNode::operator<(tNode & toCompare)
{
	return (this->character < toCompare.character);
}

/*
Helper function that returns String nickName (calls helper function in the characterInfo.cpp class, of character object)
*/
String tNode::showNickName()
{
	return this->character.getNickName();
}

/*
Helper function that retirn Game object (Data that current node hodls)
*/
Game tNode::getCharacter() 
{
	return this->character;
}

/*
Helper function that returns iList object (Data that current node holds)
*/
iList tNode::getInventory() 
{
	return this->inventory;
}

/*
Function to display content of this nodes inventory
*/
void tNode::showInventory()
{
	cout << this->inventory;
}

/*
Helper function that copies content of the passed node into this node. Uses iList and Game assignment overloads to perform deep copies
*/
void tNode::copyNode(tNode *& copyFrom)
{
	this->inventory = copyFrom->getInventory();
	this->character = copyFrom->getCharacter();
}

/*
tNode outstream overload - displays content of each node (Calls outstream overloads in iList and Game)
*/
ostream & operator<<(ostream & out, const tNode & toDisplay)
{
	out << toDisplay.inventory << toDisplay.character;
	return out;
}

/*
Default Tree (BST) constructor
*/
Tree::Tree() : root(NULL)
{
}

/*
Tree copyConstructor (not implemeted)
*/
Tree::Tree(const Tree & copyFrom) : root(NULL)
{
}

/*
Tree destructor - calls helper function
*/
Tree::~Tree()
{
	flush();
}

/*
Wrapper function for the destructor
*/
void Tree::flush()
{
	flush(root);
}

/*
Function that acts like a destructor (destroys the tree)
*/
void Tree::flush(tNode *& curr_root)
{
	if(curr_root)
	{
		flush(curr_root->getLeft());
		flush(curr_root->getRight());
		delete curr_root;
		curr_root = NULL;
	}
}

/*
Wrapper function for insertion
*/
void Tree::insert(iList & inventory_, Game & character_)
{
	recursiveInsert(root, inventory_, character_);	
}

/*
Function that performs recursive insertion 
*/
void Tree::recursiveInsert(tNode *& curr_root, iList & inventory_, Game & character_)
{
	if(!curr_root)
		curr_root = new tNode(inventory_, character_);
	else if(curr_root->getCharacter() < character_)
		recursiveInsert(curr_root->getRight(), inventory_, character_);
	else
		recursiveInsert(curr_root->getLeft(), inventory_, character_);
}

/*
Wrapper function do remove the particular player from the tree. Returns false if player doesn't exist
*/
bool Tree::removePlayer(String & nickName_)
{
	return removePlayer(root, nickName_);
}

/*
Recursive remove function. Returns false if the player doesn't exist
*/
bool Tree::removePlayer(tNode *& curr_root, String & nickName_)
{
	if(!curr_root)
		return false;

	if(curr_root->showNickName() == nickName_)
	{
		deleteNode(curr_root);
		return true;
	}
	else if(curr_root->showNickName() < nickName_)
		return removePlayer(curr_root->getRight(), nickName_);
	else
		return removePlayer(curr_root->getLeft(), nickName_);		
}

/*
Function that deletes the target node : once a player to be removed is found in the tree, Node that contains player information is sent into helper function, which (if needed) calls this function/
*/
void Tree::deleteNode(tNode *& target)
{
	tNode * temp;
	
	//Case 1: Target is a leaf (no kids)
	if(!target->getLeft() && !target->getRight())
	{
		delete target;
		target = NULL;
	}
	//Case 2a: No left child
	else if(!target->getLeft())
	{
		temp = target;
		target = target->getRight();
		temp->setRight(NULL);
		delete temp;
	}
	//Case 2b: No right child
	else if(!target->getRight())
	{
		temp = target;
		target = target->getLeft();
		temp->setLeft(NULL);
		delete temp;
	}
	//Case 3: Two children
	else
	{
		tNode * prev = NULL;
		tNode * curr = target->getRight();
		
		while(curr->getLeft())
		{
			prev = curr;
			curr = curr->getLeft();
		}

		target->copyNode(curr);

		if(!prev)
			target->setRight(curr->getRight());
		else
			prev->setLeft(curr->getRight());

		curr->setRight(NULL);
		delete curr;		
	}
}

/*
Function that finds inorder successor from the passed curr_root
*/
tNode * Tree::inOrder(tNode *& curr_root, tNode *& target)
{
	if(!curr_root)
		return NULL;
	
	if(curr_root == target)
	{
		if(curr_root->getRight())
			return rightMost(curr_root);
		else
			return target;
	}

	if(curr_root->showNickName() < target->showNickName())
	{
		return inOrder(curr_root->getRight(), target);
	}
	else
		return inOrder(curr_root->getLeft(), target);
}

/*
Function that finds inorder successor and returns pointer to that node (successor node)
*/
tNode * Tree::inOrderHelper(tNode *& curr_root, tNode *& target)
{
	tNode * successor;
	//Case 1: Right child is not NULL
	if(target->getRight())
	{
		successor = leftMost(target->getRight());
		return successor;
	}
	//Case 2: Right child is NULL
	else
	{
		tNode * right = rightMost(curr_root);

		//Case 2a: target = rightMost(curr_root)
		if(target == right)
			return right;
		else
			return inOrder(curr_root, target);
	}
}

/*
Helper function tht finds inorder successor when it is the most left node
*/
tNode * Tree::leftMost(tNode * target)
{
	if(!target->getLeft())
		return target;
	else
		return leftMost(target->getLeft());
}

/*
Function that finds inorder successor when its the most right node
*/
tNode * Tree::rightMost(tNode * target)
{
	if(!target->getRight())
		return target;
	else
		return rightMost(target->getRight());
}

/*
Wrapper function to display the tree in a tree-like way
*/
void Tree::displayTree()
{
	displayTree(root, 0);
}

/*
Recursive function that displays the tree in a tree like way using only nicknames
*/
void Tree::displayTree(tNode * curr_root, int space)
{
	if(curr_root != NULL)
	{
		displayTree(curr_root->getLeft(), space + 6);
		if(space > 0)
			cout << setw(space) << " ";
		cout << curr_root->showNickName();
		displayTree(curr_root->getRight(), space + 6);
	}
}

/*
Wrapper function that finds particular player in the tree and displays his info. Otherwise return false
*/
bool Tree::displayPlayer(String & nickName_)
{
	return displayPlayer(root, nickName_);
}

/*
Function that finds particular player in the tree and displays his info. Otherwise retur false/
*/
bool Tree::displayPlayer(tNode * curr_root, String & nickName_)
{
	if(!curr_root)
		return false;
	
	if(curr_root->showNickName() == nickName_)
	{
		cout << curr_root->getCharacter();
		curr_root->showInventory();
		return true;
	}
	else if(curr_root->showNickName() < nickName_)
		return displayPlayer(curr_root->getRight(), nickName_);
	else
		return displayPlayer(curr_root->getLeft(), nickName_);
}

/*
Wrapper function to display conent of the tree
*/
void Tree::display()
{
	if(root)
		display(root);
	else
		cout << "\nTree is empty!" << endl;
}

/*
Function that displays content of the tree (inorder traversal)
*/
void Tree::display(tNode * curr_root)
{
	if(curr_root)
	{
		display(curr_root->getLeft());
		cout << *curr_root;
		display(curr_root->getRight());
	}
}
