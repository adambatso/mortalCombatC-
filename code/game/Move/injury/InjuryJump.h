#pragma once
#include "InjuryMove.h"

/*
Character move class - injury jump move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for injury mode when hit.
*/
class InjuryJump :
	public InjuryMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	InjuryJump(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	~InjuryJump();

	//returns if the current status of the character's move is changeable
	bool changeable() const;

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);

};



