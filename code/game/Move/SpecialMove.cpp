#include "SpecialMove.h"
#include "../Player/Player.h"
#include <iostream>

SpecialMove::SpecialMove(std::vector <sf::Texture>& anime, std::vector <sf::Texture> &objects, std::vector <sf::Texture> &collide)
:Move(anime), AttackMove(anime), _object(objects, collide)
{
}


SpecialMove::~SpecialMove()
{
}

void SpecialMove::set(characterSingleton::Movement &oldMove)
{
	_changeable = false;
	_createObject = false;
	AttackMove::set(oldMove);
}

void SpecialMove::action(Player &player, Player &opponent)
{


	if (!_createObject)			//need to create special object
	{
		GeneralSingleton::instance().playSound(GeneralSingleton::specialMove);
		_createObject = true;
		if (player.opponentLeft(opponent))
			_object.set(player.getPosition().x - player.getPlayerRectangleSize().x / 2, player.getPosition().y,-1);
		else
			_object.set(player.getPosition().x + player.getPlayerRectangleSize().x / 2, player.getPosition().y, 1);
	}
			
	else
	{
		//special object exists, need to check for collision and move it
		if (!_object.collide())
		{
			AttackMove::action(player, opponent);
			_object.moveObject();
		}
		_actionMode = true;
		

		if (_object.outOfRange(opponent.getPosition()))
		{
			_actionMode = false;
			_changeable = true;
		}
			
		if (_object.collide() && _object.endOfAnimation())
		{
			_actionMode = false;
			_changeable = true;
		}
			

	}

}

bool SpecialMove::checkIfCollision(Player &player, Player &opponent)
{
	sf::FloatRect rec1 = _object.getFloatRect();
	sf::FloatRect rec2 = opponent.getFloatRect();


	if (rec1.intersects(rec2))
	{
		_object.updateCollide();
		return true;
	}
		


	return false;
}

void SpecialMove::draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent)
{
	Move::draw(window, position, opponent);
	_object.draw(window);

}

bool SpecialMove::checkBlock(Player &opponent)
{
	return opponent.isGneralBlock();
}

int SpecialMove::getDamage(Player &player) const
{
	return player.getSpecialPower();
}

int SpecialMove::getDamageOpponentBlock(Player &player) const
{
	return player.getSpecialPower() * BLOCKFACTOR;
}

bool SpecialMove::changeable() const
{
	return _changeable;
}

void SpecialMove::nextFrame()
{
	if (_animPos < _animationMove.size() - 1)
		_animPos++;
}

