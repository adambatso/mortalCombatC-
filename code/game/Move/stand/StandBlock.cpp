#include "StandBlock.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites
StandBlock::StandBlock(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
StandBlock::~StandBlock()
{
}

//set function - sets all the class members to default
void StandBlock::set(characterSingleton::Movement &oldMove)
{
	if (characterSingleton::standblock != oldMove)
	{
		_animPos = 0;
		_actionMode = true;
	}


}

//returns if the current status of the character's move is changeable
bool StandBlock::changeable() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E))
		return false;

	return true;
}