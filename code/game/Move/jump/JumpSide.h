#pragma once
#include "JumpMove.h"

/*
Character move class - attack move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
*/
class JumpSide :
	public JumpMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	JumpSide(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	~JumpSide();

};

