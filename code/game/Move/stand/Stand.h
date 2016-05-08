#pragma once
#include "../Move.h"

/*
Character move class - stand move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the move,set and the next frame to draw.
*/
class Stand :
	public Move
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	Stand(std::vector <sf::Texture>& anime);

	//default d-tor
	~Stand();

	//set function - sets all the class members to default
	void set(characterSingleton::Movement &oldMove);

	//updates to appropriate image in the texture's vector
	void nextFrame();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);
};


