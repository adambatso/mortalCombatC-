#include "Player.h"
#include <iostream>

//c-tor - arguments: pos - the player's position on the screen at the start of the game,
//nameOfCharacter - in order to load the appropriate textures
Player::Player(sf::Vector2f pos, charName nameOfCharacter):
_position(pos), _state(nameOfCharacter)
{
	switch (nameOfCharacter)
	{
	case characterSingleton::subZero:
		_characterSkills = std::make_unique<CharacterSkillSubZero>();
		break;
	case characterSingleton::sonya:
		_characterSkills = std::make_unique<CharacterSkillSonya>();
		break;
	case characterSingleton::liuKang:
		_characterSkills = std::make_unique<CharacterSkillLiuKang>();
		break;
	case characterSingleton::kitana:
		_characterSkills = std::make_unique<CharacterSkillKitana>();
		break;
	default:
		break;
	}
}


//default d-tor
Player::~Player()
{
}

//function is responsible to transfer the window to draw for current move
void Player::draw(sf::RenderWindow &window, Player &opponent)
{
	_state.draw(window, _position, opponent);
}

//returns the position of the player on the screen
sf::Vector2f Player::getPosition() const
{
	return _position;
}

//checks if the player can use is current move and summons it if needed
void Player::action(Player &opponent)
{
	if (_state.executeAction())
	{
		_state.action(*this, opponent);
	}
}

//moves the player in the screen by received argument (in pixles)
void Player::move(float pixOffsetX, float pixOffsetY)
{

	_position.x += pixOffsetX;
	_position.y += pixOffsetY;
}

//returns the size of the current sprite the character is in it
sf::Vector2f Player::getPlayerRectangleSize()
{
	return _state.getPlayerRectangleSize();
}

//returns the float rectangle by according to character's current texture
sf::FloatRect Player::getFloatRect()
{
	return _state.getFloatRect(_position);
}

//set the injury mode (stand/duck/jump) the character needs to be, and decreases its
//life by received parameter
void Player::setInjury(int parameter, Player &attacker)
{
	_life -= parameter;
	_state.setInjury(*this, attacker);

}

// returns the life of the player
int Player::getLife() const
{
	return _life;
}

//moves the player down in order to duck in the screen by received argument (in pixles)
void Player::lowerPosition(float pixOffset)
{
	_position.y += pixOffset;
}

//set new position of the player by received argument - newPos
void Player::setPosition(sf::Vector2f newPos)
{
	_position = newPos;
}

//returns if the player is ducking, including all the duck moves
bool Player::inDuckMode() const
{
	return _state.isDuckMode();
}

//set new move of the player by received argument - newMove
void Player::setMove(characterSingleton::Movement newMove)
{
	_state.setMove(newMove);
}

//returns if the player can change is move
bool Player::changeable()
{
	return _state.changeable();
}

//returns the current move the player is in
characterSingleton::Movement Player::getCurrentMode() const
{
	return _state.getCurrent();
}

//returns if the player is in a jump that can changed
bool Player::changeableJump() const
{
	if (_state.getCurrent() == characterSingleton::jumpsideLeft ||
		_state.getCurrent() == characterSingleton::jumpsideRight)
	{
		return true;
	}

	return false;
}

//returns true if the oppnent is left to player,else - the opponent is right to 
//the player and return false
bool Player::opponentLeft(const Player &opponent) const
{
	if (_position.x > opponent._position.x)
		return true;
	return false;
}

//decrease the life of the player by received argument
void Player::decreaseLife(int parameter)
{
	_life -= parameter;
}

//return if character is jumping
bool Player::isJumpMode() const
{
	
	return _state.isJumpMode();
}


//return power of kick attack
int Player::getKickPower() const
{
	return _characterSkills->getKickPower();
}

//return power of punch attack
int Player::getPunchPower() const
{
	return _characterSkills->getPunchPower();
}

//return power of special attack
int Player::getSpecialPower() const
{
	return _characterSkills->getSpecialPower();
}