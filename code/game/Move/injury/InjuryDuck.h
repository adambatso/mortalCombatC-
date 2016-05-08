#pragma once
#include "InjuryMove.h"

/*
Character move class - injury duck move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for injury mode when hit.
*/
class InjuryDuck :
	public InjuryMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	InjuryDuck(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	~InjuryDuck();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);
};

