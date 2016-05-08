#include "HumanPlayer.h"
#include <iostream>

//c-tor - arguments: nameOfCharacter - in order to load the appropriate textures
HumanPlayer::HumanPlayer(charName nameOfCharacter)
:Player(sf::Vector2f(300,450), nameOfCharacter)
{
}

//default d-tor
HumanPlayer::~HumanPlayer()
{
}

//function updates character's move by user's pressed key.
//arguments: keys - vector of last pressed keys, opponent - to update 
//if neseccery
void HumanPlayer::move(std::vector<sf::Keyboard::Key> &keys, Player &opponent)
{
	sf::Keyboard::Key pressedKey;	//holds the pressed key from key vector

	//if the current move at the moment is not changeable - return and dont change
	if (!_state.changeable())
		return;
	
	int index = 0;	//index in key vectoer

	//if player is jumping and can change to attack jump
	if (_state.isJumpSideLeft() || _state.isJumpSideRight())
	{
		if (keys.size() != 0)
		{
			pressedKey = keys[index];

			switch (pressedKey)
			{

			case sf::Keyboard::Q:			//higth punch
				if (_state.isJumpSideLeft())
					_state.setMove(characterSingleton::jumppunchleft);
				else if (_state.isJumpSideRight())
					_state.setMove(characterSingleton::jumppunchright);

				return;
				break;
			case sf::Keyboard::A:			//higth kick
				if (_state.isJumpSideLeft())
					_state.setMove(characterSingleton::jumpkickleft);
				else if (_state.isJumpSideRight())
					_state.setMove(characterSingleton::jumpkickright);

				return;
			}
		}
		return;

	}

	//search for special combination
	for (size_t pos = 0; pos < keys.size(); pos++)
	{
		std::cout << sf::Keyboard::Key(keys[pos]) << std::endl;
	}

	sf::Keyboard::Key wantdKey = sf::Keyboard::A;
	for (size_t pos = 0; pos < keys.size(); pos++)
	{
		if (keys[pos] == wantdKey)
		{
			if (suitableCombination(keys, pos))
			{
				_state.setMove(characterSingleton::specialAttack);
				return;
			}
		}
	}
	
	//default situation
	while (true)
	{
		//if user pressed down to duck
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		{
			if (index == keys.size() || keys.size() == 0)
			{
				_state.setMove(characterSingleton::ducking);
				return;
			}		

			pressedKey = keys[index];

			switch (pressedKey)
			{
			case sf::Keyboard::E:			// block
				_state.setMove(characterSingleton::duckblock);
				return;
				break;

			case sf::Keyboard::Q:			//higth punch
				_state.setMove(characterSingleton::duckhighpunch);
				return;
				break;
			case sf::Keyboard::S:			//low kick
				_state.setMove(characterSingleton::duckkick);
				return;

				break;

			case sf::Keyboard::W:			//low punch
				_state.setMove(characterSingleton::ducklowpunch);
				return;
				break;



			}

		}
		//if user pressed up to jump
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		{
			if (index == keys.size() || keys.size() == 0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
				{
					_state.setMove(characterSingleton::jumpsideLeft);
					return;
				}

				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
				{
					_state.setMove(characterSingleton::jumpsideRight);
					return;
				}

			}
				

			

		}

		//normal move - standing
		else
		{
			setPosition(sf::Vector2f(getPosition().x, GROUNDSTAND));
			if (index == keys.size() || keys.size()==0)
			{
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
					_state.setMove(characterSingleton::walkingLeft);
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
					_state.setMove(characterSingleton::walkingRight);
				else
					_state.setMove(characterSingleton::stand);

				return;
			}


			pressedKey = keys[index];

			switch (pressedKey)
			{
			case sf::Keyboard::E:			// block
				_state.setMove(characterSingleton::standblock);
				return;
				break;

			case sf::Keyboard::A:			//higth kick
				_state.setMove(characterSingleton::highkick);
				return;
				break;

			case sf::Keyboard::Q:			//higth punch
				_state.setMove(characterSingleton::highpunch);
				return;
				break;
			case sf::Keyboard::S:			//low kick
				_state.setMove(characterSingleton::lowkick);
				return;
				break;

			case sf::Keyboard::W:			//low punch
				_state.setMove(characterSingleton::lowpunch);
				return;
				break;

			}

		}

		index++;		//there was no correct key combination - go to next key
	}
	

}

//returns if character is standing and blocking
bool HumanPlayer::isStandBlock()
{
	if (_state.getCurrent() == characterSingleton::standblock)
		return true;

	return false;
}

//returns if character is ducking and blocking
bool HumanPlayer::isDuckBlock()
{
	if (_state.getCurrent() == characterSingleton::duckblock)
		return true;

	return false;
}

//returns if character is blocking (ducking/standing)
bool HumanPlayer::isGneralBlock()
{
	characterSingleton::Movement curr = _state.getCurrent();

	if (curr == characterSingleton::duckblock || curr == characterSingleton::standblock)
		return true;

	return false;
}

//returns if user used special combination of keys to set special attack
bool HumanPlayer::suitableCombination(std::vector<sf::Keyboard::Key> &keys,size_t currPos)
{
	if (currPos + 1 > keys.size() - 1)
		return false;

	if (keys[currPos + 1] == sf::Keyboard::Key::S )
		return true;

	return false;
}