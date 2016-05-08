#include "InjuryJump.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
InjuryJump::InjuryJump(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), InjuryMove(anime, offset, direction)
{
}

//default d-tor
InjuryJump::~InjuryJump()
{
}

//returns if the current status of the character's move is changeable
bool InjuryJump::changeable() const
{

	return false;
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void InjuryJump::action(Player &player, Player &opponent)
{
	if (player.getPosition().y >= GROUNDSTAND)
		_actionMode = false;

	if (_actionMode)
	{
		if (_direction == characterSingleton::jumpbeinghitLeft)
		{
			if (player.getPosition().x - player.getPlayerRectangleSize().x / 2>0)
				player.move(_offset, 0.5);
		}
		else
		{
			if (player.getPosition().x + player.getPlayerRectangleSize().x / 2<WINDOWX)
				player.move(_offset, 0.5);
		}
	}


	else
		player.setMove(characterSingleton::stand);

}