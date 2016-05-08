#include "DuckBlock.h"

//c-tor - arguments: anime - vector that holds the move sprites
DuckBlock::DuckBlock(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
DuckBlock::~DuckBlock()
{
}

//set function - sets all the class members to default
void DuckBlock::set(characterSingleton::Movement &oldMove)
{
	//dont sets as new if current move is same (duckblock)
	if (characterSingleton::duckblock != oldMove)
	{
		_animPos = 0;
		_actionMode = true;
	}

}

//returns if the current status of the character's move is changeable
bool DuckBlock::changeable() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::E) && sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return false;

	return true;
}