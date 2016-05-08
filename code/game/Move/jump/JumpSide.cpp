#include "JumpSide.h"

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
JumpSide::JumpSide(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
: Move(anime), MovePosition(anime, offset, direction), JumpMove(anime, offset, direction)
{
}

//default d-tor
JumpSide::~JumpSide()
{
}
