#include "MovePosition.h"


//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
MovePosition::MovePosition(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), _offset(offset), _direction(direction)
{
}

//default d-tor
MovePosition::~MovePosition()
{
}

//set function - sets all the class members to default
void MovePosition::set(characterSingleton::Movement &oldMove)
{
	if (_direction != oldMove)
	{
		Move::set(oldMove);
	}
}

//updates to appropriate image in the texture's vector
void MovePosition::nextFrame()
{
	_animPos = (_animPos + 1) % _animationMove.size();
}