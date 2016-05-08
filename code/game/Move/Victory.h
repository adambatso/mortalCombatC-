#pragma once
#include "Move.h"

/*
Character victory move class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
*/
class Victory :
	public Move
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	Victory(std::vector <sf::Texture>& anime);

	//default d-tor
	~Victory();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);
};

