#include "InjuryDuck.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
InjuryDuck::InjuryDuck(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), InjuryMove(anime, offset, direction)
{
}

//default d-tor
InjuryDuck::~InjuryDuck()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void InjuryDuck::action(Player &player, Player &opponent)
{

	//check witch direction to move the player
	if (_direction == characterSingleton::duckbeinghitLeft)
	{
		if (player.getPosition().x - player.getPlayerRectangleSize().x / 2>0)
			player.move(_offset, 0);
	}
	else
	{
		if (player.getPosition().x + player.getPlayerRectangleSize().x / 2<WINDOWX)
			player.move(_offset, 0);
	}

	//if to stop summoning the action function
	if (_animPos == _animationMove.size() - 1)
		_actionMode = false;
}