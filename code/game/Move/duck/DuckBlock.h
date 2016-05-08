#pragma once
#include "../Move.h"

/*
Character move class - attack move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the block and returns when it can change move.
*/
class DuckBlock :
	public Move
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	DuckBlock(std::vector <sf::Texture>& anime);

	//default d-tor
	~DuckBlock();

	//set function - sets all the class members to default
	void set(characterSingleton::Movement &oldMove);

	//returns if the current status of the character's move is changeable
	bool changeable() const;

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent){};
};

