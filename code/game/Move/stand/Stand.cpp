#include "Stand.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
Stand::Stand(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
Stand::~Stand()
{
}

//set function - sets all the class members to default
void Stand::set(characterSingleton::Movement &oldMove)
{
	if (characterSingleton::stand != oldMove)
	{
		Move::set(oldMove);
	}
}

//updates to appropriate image in the texture's vector
void Stand::nextFrame()
{
	_animPos = (_animPos + 1) % _animationMove.size();
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void Stand::action(Player &player, Player &opponent)
{
	if (_actionMode)
	{
		player.setPosition(sf::Vector2f(player.getPosition().x,GROUNDSTAND));
		_actionMode = false;
	}
		

}