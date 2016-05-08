#include "AttackMove.h"
#include "../Player/Player.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites
AttackMove::AttackMove(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
AttackMove::~AttackMove()
{
}

//returns if the current status of the character's move is changeable
bool AttackMove::changeable() const
{
	if (_animPos == 0)
		return true;

	return false;
}

//updates to appropriate image in the texture's vector
void AttackMove::nextFrame()
{
	if (_animPos == _animationMove.size() - 1)
		_forwardFrame = false;

	if (_forwardFrame)
		_animPos++;
	else
	{
		if (_animPos > 0)
			_animPos--;
	}
}

//set function - sets all the class members to default
void AttackMove::set(characterSingleton::Movement &oldMove)
{
	_animPos = 0;
	_actionMode = true;
	_forwardFrame = true;
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void AttackMove::action(Player &player, Player &opponent)
{
	
	if (checkIfCollision(player, opponent))
	{

		if (checkBlock(opponent))				//oppnent is blocking
			opponent.decreaseLife(getDamageOpponentBlock(player));
		else
			opponent.setInjury(getDamage(player), player);		//oppnent not blocking

		std::cout << opponent.getLife() << std::endl;
		_actionMode = false;
		playSoundtype();
	}

}

//function returns true if there is a collision between the character to its opponent
//else - return false
bool AttackMove::checkIfCollision(Player &player, Player &opponent)
{
	sf::FloatRect rec1 = player.getFloatRect();
	sf::FloatRect rec2 = opponent.getFloatRect();

	if (rec1.intersects(rec2))
	{
		return true;
	}
		

	return false;
}