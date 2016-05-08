#pragma once
#include "../MovePosition.h"

/*
Character move class - stand move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the move.
*/
class Walking :
	public MovePosition
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	Walking(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	~Walking();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);
};

