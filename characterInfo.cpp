/*
Illia Shershun
CS202 Spring

Class that implements characterInfo.h
*/

#include "characterInfo.h"

/*
Default constructor
*/
Personal::Personal()
{
}

/*
Constructor with parameters - uses String class overload to copy data
*/
Personal::Personal(String & name_, String & email_, String & phoneNumber_)
{
	name = name_;
	email = email_;
	phoneNumber = phoneNumber_;
}

/*
Copy constructor - uses string class overload to copy data
*/
Personal::Personal(const Personal & copyFrom)
{
	name = copyFrom.name;
	email = copyFrom.email;
	phoneNumber = copyFrom.phoneNumber;
} 

/*
Destructor - calls String class destructor for the data (name, email, phoneNumber)
*/
Personal::~Personal()
{
}

/*
Assignment overload - uses String class overlaod to copy data
*/
Personal & Personal::operator=(const Personal & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		name = copyFrom.name;
		email = copyFrom.email;
		phoneNumber = copyFrom.phoneNumber;
	}

	return *this;
}

/*
Outstream overload - displays personal information
*/
ostream & operator<<(ostream & out, const Personal & toDisplay)
{
	out << "\n-----------------PERSONAL INFO---------------";
	out << "\nName: " << toDisplay.name << "Email: " << toDisplay.email << "Phone number: " << toDisplay.phoneNumber;
	out << "---------------------------------------------" << endl;
	return out;
}

/*
Default Game constructor
*/
Game::Game()
{
}

/*
Game constructor with arugments - uses initialization list to kick-start base class constructor, then copies passed data using String assignment overload
*/
Game::Game(String & name_, String & email_, String & phoneNumber_, String & nickName_, String & characterType_, Visual & visualInfo_) : Personal(name_, email_, phoneNumber_)
{
	nickName = nickName_;
	characterType = characterType_;
	visualInfo = visualInfo_;	
}

/*
Copy constructor - uses String assignment overload to copy data
*/
Game::Game(Game & copyFrom) : Personal(copyFrom.name, copyFrom.email, copyFrom.phoneNumber)
{
	nickName = copyFrom.nickName;
	characterType = copyFrom.characterType;
	visualInfo = copyFrom.visualInfo;
}

/*
Game destructor - calls String destructor for nickName and characterType
*/
Game::~Game()
{
}

/*
Helper function that returns nickName (String)
*/
String Game::getNickName()
{
	return this->nickName;
}

/*
Game assignment overload - uses String class assignment overlaod to deep copy data
*/
Game & Game::operator=(const Game & copyFrom)
{
	if(this == &copyFrom)
		return *this;
	else
	{
		Personal::operator=(copyFrom);
		nickName = copyFrom.nickName;
		characterType = copyFrom.characterType;
		visualInfo = copyFrom.visualInfo;
	}

	return *this;
}

/*
Game less than operator. Used in BST to compare nickNames. Calls String class less than overload 
*/
bool Game::operator<(Game & toCompare)
{
	return (this->nickName < toCompare.nickName);
}

/*
Outstream overload : displays complete information of the character (both personal and game info)
*/
ostream & operator<<(ostream & out, const Game & toDisplay)
{
	const Personal & personal(toDisplay);
	out << personal;
	out << "------------------GAME INFO------------------" << endl;
	out << "Nickname: " << toDisplay.nickName << "Character Type: " << toDisplay.characterType << "Visuals: " << toDisplay.visualInfo;
	out << "---------------------------------------------" << endl;
	return out;
}
