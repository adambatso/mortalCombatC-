#include "InjuryMove.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
InjuryMove::InjuryMove(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), MovePosition(anime, offset, direction)
{
}

//default d-tor
InjuryMove::~InjuryMove()
{
}

//returns if the current status of the character's move is changeable
bool InjuryMove::changeable() const
{
	if (_animPos == _animationMove.size() - 1)
		return true;

	return false;
}

//updates to appropriate image in the texture's vector
void InjuryMove::nextFrame()
{
	if (_animPos != _animationMove.size() - 1)
		_animPos++;
}

