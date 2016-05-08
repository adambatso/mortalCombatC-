#pragma once
#include "../MovePosition.h"

/*
Character move class - jump move.
Abstract class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the jump moves who inherits from it.
*/
class JumpMove :
	virtual public MovePosition
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	JumpMove(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	virtual ~JumpMove();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	virtual void action(Player &player, Player &opponent);

	//set function - sets all the class members to default
	virtual void set(characterSingleton::Movement &oldMove);

	//returns if the current status of the character's move is changeable
	virtual bool changeable() const;

	//returns witch injury mode (stand/duck/jump) the character needs to be
	virtual characterSingleton::Movement getAppropriateInjuryMode(Player &injured, Player &attacker) const;

	//updates to appropriate image in the texture's vector
	void nextFrame();
protected:
	bool _up = false;		//if character is going up/down
};


