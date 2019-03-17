/*
Illia Shershun
CS202 Spring

Class to interact with the user.
*/

#include "item.h"
#include "characterInfo.h"
#include "itemList.h"
#include "avatar.h"
#include "bst.h"

char readCommand();
void showMenu();
void processMenu(char command, Avatar & avatar_, iList & inventory_, Game & character_, History & history_, Tree & BST_);
void setCharacter(Game & character_);
void setInventory(iList & inventory_);
void setItem(Item & item_);
void setHistory(History & history_);

int main()
{	
	char cmd;
	Avatar avatar;
	iList inventory;
	Game character;
	History history;
	Tree BST;
	
	showMenu();
	cmd = readCommand();

	while(cmd != 'q' && cmd != 'Q')
	{
		cin.ignore(50, '\n');
		cin.clear();
		processMenu(cmd, avatar, inventory, character, history, BST);
		showMenu();
		cmd = readCommand();
	}
	
	return 0;
}

/*
Helper function to read user command
*/
char readCommand()
{
	char ch;
	cout << "\nYour choice: ";
	cin >> ch;
	
	return ch;
}

/*
Function to display menu
*/
void showMenu()
{
	cout << "\n----------------MENU----------------";
	cout << "\n1) Press 1 to create new character (avatar): ";
	cout << "\n2) Press 2 to display the tree: ";
	cout << "\n3) Press 3 to display tree in a tree-way: ";
	cout << "\n4) Press 4 to find players info: ";
	cout << "\n5) Press 5 to delete particular player: ";
	cout << "\n6) Press 6 to delete the tree: ";
	cout << "\nPress Q(q) to quit: ";
}

/*
Function to process user input and do appropriate action
*/
void processMenu(char command, Avatar & avatar_, iList & inventory_, Game & character_, History & history_, Tree & BST_)
{
	switch(command)
	{
		case '1':
			{
				cout << "\n**********SETTING NEW GAME CHARACTER*********";
				setCharacter(character_);
				setInventory(inventory_);
				setHistory(history_);

				Avatar temp(inventory_, history_, character_);

				BST_.insert(inventory_, character_);
				cout << "**********************************************" << endl;
				break;
			}
		case '2':
			{
				cout << "\n*********DISPLAYING TREE INFORMATION*********";
				BST_.display();
				cout << "***********************************************" << endl;
				break;
			}
		case '3': 
			{
				cout << "\n*********DISPLAYING TREE NICKNAMES**********\n";
				BST_.displayTree();
				cout << "\n*********************************************" << endl;
				break;
			}
		case '4':
			{
				cout << "\n**********PLAYER SEARCH**********";
				String search;
				cout << "\nEnter players nickname (game name): ";
				cin >> search;

				bool show = BST_.displayPlayer(search);
				if(!show)
					cout << "\nError. Player doesn't exist!" << endl;

				cout << "**********************************" << endl;
				break;
			}
		case '5':
			{
				cout << "\n**********DELETING PLAYER**********";
				String toDelete;
				cout << "\nEnter players nickname (game name): ";
				cin >> toDelete;
			
				bool rmv = BST_.removePlayer(toDelete);
				if(!rmv)
					cout << "\nError. Player doesn't exist!" << endl;
				cout << "************************************" << endl;
				break;
			}
		case '6':
			{
				cout << "\n**********DELETING TREE***********";
				BST_.flush();
				cout << "\n***********************************" << endl;
				break;
			}
		case 'q': break;
		case 'Q': break;
		default:
			{
				cout << "\nIllegal command!" << endl;
				break;
			}
	}
}

/*
Helper function to set character (set a complete Game object)
*/
void setCharacter(Game & character_)
{	
	String name;
	String email;
	String phone;
	String nickName;
	String type;
	String gender;
	String bodyType;
	double height;

	cout << "\n---------SETTING NEW PLAYER----------";
	cout << "\nYour real name: ";
	cin >> name;
	cout << "Email: ";
	cin >> email;
	cout << "Phone number: ";
	cin >> phone;
	cout << "Nickname in the game: ";
	cin >> nickName;
	cout << "Character type (dueler, adventurist, builder etc.): ";
	cin >> type;
	cout << "Character gender: ";
	cin >> gender;
	cout << "Character body type (muscular, fat, normal): ";
	cin >> bodyType;
	cout << "Character height: ";
	cin >> height;
	cin.ignore(50, '\n');
	cin.clear();
	cout << "--------------------------------------" << endl;

	Visual vsl(gender, bodyType, height);
	Game temp(name, email, phone, nickName, type, vsl);
	character_ = temp;
}

/*
Function that sets inventory (complete iList object). Calls another helper function to set items, until user doesn't want to add any more items.
*/
void setInventory(iList & inventory_)
{
	Item newItem;
	char chs;

	while(chs !='n' && chs != 'N')
	{
		setItem(newItem);
		inventory_+newItem;

		cout << "Add more?(Y/N)";
		cin.get(chs);
		cin.ignore(50, '\n');
                cin.clear();
	}
}

/*
Helper function that sets an item (complete Item object)
*/
void setItem(Item & item_)
{
	String name;
	String use;

	cout << "\n----------SETTING NEW ITEM---------";
	cout << "\nItem name: ";
	cin >> name;
	cout << "Use (wear, eat etc): ";
	cin >> use;
	cout << "-------------------------------------" << endl;

	item_.setName(name);
	item_.setUse(use);
}

/*
Function that sets history (complete History object)
*/
void setHistory(History & history_)
{
	int awards;
	double hrs_played;

	cout << "\n---------SETTING HISTORY----------";
	cout << "\nEnter number of awards received (int): ";
	cin >> awards;
	cout << "Enter hours played (double): ";
	cin >> hrs_played;	
	cout << "------------------------------------" << endl;

	History temp(awards, hrs_played);
	
	history_ = temp;
}
