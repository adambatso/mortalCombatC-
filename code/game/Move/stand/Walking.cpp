#include "Walking.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
Walking::Walking(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), MovePosition(anime, offset, direction)
{
}

//default d-tor
Walking::~Walking()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void Walking::action(Player &player, Player &opponent)
{
	sf::Vector2f PlayerSize = player.getPlayerRectangleSize();

	if (_direction == characterSingleton::walkingLeft)
	{
		if (opponent.getPosition().x > player.getPosition().x && player.getPosition().x - PlayerSize.x / 2>0)				//opponent is on the right
		{
			player.move(_offset, 0);
			return;
		}

		if (opponent.getPosition().x + opponent.getPlayerRectangleSize().x / 2<player.getPosition().x - player.getPlayerRectangleSize().x / 2
			&& player.getPosition().x - PlayerSize.x / 2>0)
		{
			player.move(_offset, 0);
			return;
		}
	}
	else
	{
		if (opponent.getPosition().x < player.getPosition().x && player.getPosition().x + PlayerSize.x / 2<WINDOWX)				//opponent is on the left
		{
			player.move(_offset, 0);
			return;
		}
		if (opponent.getPosition().x - opponent.getPlayerRectangleSize().x / 2 >player.getPosition().x + player.getPlayerRectangleSize().x / 2
			&& player.getPosition().x + PlayerSize.x / 2<WINDOWX)
		{
			player.move(_offset, 0);
			return;
		}
	}

	if (_animPos == _animationMove.size() - 1)
		_actionMode = false;
}