#pragma once
#include "../Move.h"

/*
Character move class - attack move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action,set and injury mode when hit.
*/
class Ducking :
	public Move
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	Ducking(std::vector <sf::Texture>& anime);

	//default d-tor
	~Ducking();

	//set function - sets all the class members to default
	void set(characterSingleton::Movement &oldMove);

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);

	//returns witch injury mode (stand/duck/jump) the character needs to be
	characterSingleton::Movement getAppropriateInjuryMode(Player &injured, Player &attacker) const;

};

