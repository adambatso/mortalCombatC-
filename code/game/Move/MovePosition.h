#pragma once
#include "Move.h"

/*
Character move class - position changer move.
Abstract class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the moves, that changes the player position
in the window ,who inherits from it.
*/
class MovePosition :
	virtual public Move
{
public:
	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	MovePosition(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	virtual ~MovePosition();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	virtual void action(Player &player, Player &opponent){};

	//set function - sets all the class members to default
	virtual void set(characterSingleton::Movement &oldMove);

	//updates to appropriate image in the texture's vector
	virtual void nextFrame();

protected:
	float _offset;								//offset on screen for object
	characterSingleton::Movement _direction;	//witch direction to go

};

