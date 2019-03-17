/*
Illia Shershun
CS202 Spring

Class that stores information about the player - both real life info and in-game info
*/

#ifndef CHRTR_H
#define CHRTR_H

#include "string.h"
#include "visual.h"

class Personal
{
public:
	Personal();
	Personal(String & name_, String & email_, String & phoneNumber_);
	Personal(const Personal & copyFrom);

	~Personal();

	Personal & operator=(const Personal & copyFrom);
	friend ostream & operator<<(ostream & out, const Personal & toDisplay);
protected:
	String name;
	String email;
	String phoneNumber;
};

class Game : public Personal
{
public:
	Game();
	Game(String & name_, String & email_, String & phoneNumber_, String & nickName_, String & characterType_, Visual & visualInfo_);
	Game(Game & copyFrom);

	~Game();

	String getNickName();
	
	Game & operator=(const Game & copyFrom);
	bool operator<(Game & toCompare);
	friend ostream & operator<<(ostream & out, const Game & toDisplay);
private:
	String nickName;
	String characterType;
	Visual visualInfo;
};

#endif
