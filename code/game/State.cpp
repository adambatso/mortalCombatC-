#include "State.h"
#include <iostream>

//c-tor - arguments: nameOfCharacter - to get the appropriate textures of the character
State::State(charName nameOfCharacter)
{

	std::unique_ptr <Move> temp(new Stand(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::stand)));
	_movemap[characterSingleton::stand] = std::move(temp);

	temp.reset(new LowKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::lowkick)));
	_movemap[characterSingleton::lowkick] = std::move(temp);

	temp.reset(new Walking(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::walking), -0.15, characterSingleton::walkingLeft));
	_movemap[characterSingleton::walkingLeft] = std::move(temp);

	temp.reset(new Walking(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::walking), 0.15, characterSingleton::walkingRight));
	_movemap[characterSingleton::walkingRight] = std::move(temp);

	temp.reset(new DuckBlock(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::duckblock)));
	_movemap[characterSingleton::duckblock] = std::move(temp);

	temp.reset(new StandBlock(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::standblock)));
	_movemap[characterSingleton::standblock] = std::move(temp);

	temp.reset(new DuckHighPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::duckhighpunch)));
	_movemap[characterSingleton::duckhighpunch] = std::move(temp);

	temp.reset(new Ducking(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::ducking)));
	_movemap[characterSingleton::ducking] = std::move(temp);

	temp.reset(new DuckKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::duckkick)));
	_movemap[characterSingleton::duckkick] = std::move(temp);

	temp.reset(new DuckLowPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::ducklowpunch)));
	_movemap[characterSingleton::ducklowpunch] = std::move(temp);

	temp.reset(new HighKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::highkick)));
	_movemap[characterSingleton::highkick] = std::move(temp);

	temp.reset(new HighPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::highpunch)));
	_movemap[characterSingleton::highpunch] = std::move(temp);

	temp.reset(new JumpKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpkick), -0.2, characterSingleton::jumpkickleft));
	_movemap[characterSingleton::jumpkickleft] = std::move(temp);

	temp.reset(new JumpKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpkick), 0.2, characterSingleton::jumpkickright));
	_movemap[characterSingleton::jumpkickright] = std::move(temp);

	temp.reset(new JumpPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumppunch), -0.2, characterSingleton::jumppunchleft));
	_movemap[characterSingleton::jumppunchleft] = std::move(temp);

	temp.reset(new JumpPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumppunch), 0.2, characterSingleton::jumppunchright));
	_movemap[characterSingleton::jumppunchright] = std::move(temp);

	temp.reset(new JumpSide(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpside), -0.2, characterSingleton::jumpsideLeft));
	_movemap[characterSingleton::jumpsideLeft] = std::move(temp);

	temp.reset(new JumpSide(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpside), 0.2, characterSingleton::jumpsideRight));
	_movemap[characterSingleton::jumpsideRight] = std::move(temp);

	temp.reset(new LowPunch(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::lowpunch)));
	_movemap[characterSingleton::lowpunch] = std::move(temp);

	temp.reset(new InjuryDuck(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::duckbeinghit), -0.2, characterSingleton::duckbeinghitLeft));
	_movemap[characterSingleton::duckbeinghitLeft] = std::move(temp);

	temp.reset(new InjuryDuck(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::duckbeinghit), 0.2, characterSingleton::duckbeinghitRight));
	_movemap[characterSingleton::duckbeinghitRight] = std::move(temp);

	temp.reset(new InjuryJump(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpbeinghit), -0.2, characterSingleton::jumpbeinghitLeft));
	_movemap[characterSingleton::jumpbeinghitLeft] = std::move(temp);

	temp.reset(new InjuryJump(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::jumpbeinghit), 0.2, characterSingleton::jumpbeinghitRight));
	_movemap[characterSingleton::jumpbeinghitRight] = std::move(temp);

	temp.reset(new InjuryStand(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::standbeinghit), -0.2, characterSingleton::standbeinghitLeft));
	_movemap[characterSingleton::standbeinghitLeft] = std::move(temp);

	temp.reset(new InjuryStand(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::standbeinghit), 0.2, characterSingleton::standbeinghitRight));
	_movemap[characterSingleton::standbeinghitRight] = std::move(temp);

	temp.reset(new Victory(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::victory)));
	_movemap[characterSingleton::victory] = std::move(temp);

	temp.reset(new Defeat(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::Defeat)));
	_movemap[characterSingleton::Defeat] = std::move(temp);

	temp.reset(new SpecialMove(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::specialAttack), 
		characterSingleton::instance().getSpecialMove(nameOfCharacter, characterSingleton::objectMove),
		characterSingleton::instance().getSpecialMove(nameOfCharacter, characterSingleton::objectcollide)));
	_movemap[characterSingleton::specialAttack] = std::move(temp);

	//_movemap.emplace(characterSingleton::stand, new Stand(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::stand)));
	//_movemap.emplace(characterSingleton::lowkick, new LowKick(characterSingleton::instance().getMovement(nameOfCharacter, characterSingleton::lowkick)));
}

//default d-tor
State::~State()
{
}

//function is responsible to transfer the window to draw for current move
void State::draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent)
{
	_movemap[_currentMode]->draw(window, position, opponent);

}

//returns the current move the character is in
characterSingleton::Movement State::getCurrent() const
{
	return _currentMode;
}

//sets the received argument as the new move of the character
void State::setMove(characterSingleton::Movement newMove)
{
	_movemap[newMove]->set(_currentMode);
	_currentMode = newMove;
}

//returns if the current move can be change
bool State::changeable()
{
	return _movemap[_currentMode]->changeable();
}

//returns if the character stands - including all the moves of standing
bool State::isStandMode() const
{
	if (_currentMode == characterSingleton::stand ||
		_currentMode == characterSingleton::highpunch ||
		_currentMode == characterSingleton::highkick ||
		_currentMode == characterSingleton::lowpunch ||
		_currentMode == characterSingleton::lowkick ||
		_currentMode == characterSingleton::standblock)
		return true;

	return false;
}

//returns if the character ducking - including all the moves of ducking
bool State::isDuckMode() const
{
	if (_currentMode == characterSingleton::ducking ||
		_currentMode == characterSingleton::duckhighpunch ||
		_currentMode == characterSingleton::duckkick ||
		_currentMode == characterSingleton::ducklowpunch ||
		_currentMode == characterSingleton::duckblock)
		return true;

	return false;
}

//returns if the character jumps to the left
bool State::isJumpSideLeft() const
{
	if (_currentMode == characterSingleton::jumpsideLeft)
		return true;

	return false;
}

//returns if the character jumps to the right
bool State::isJumpSideRight() const
{
	if (_currentMode == characterSingleton::jumpsideRight)
		return true;

	return false;
}

//returns if current move is in action mode
bool State::executeAction()
{
	return _movemap[_currentMode]->getActionMode();
}

//summons action of current move
void State::action(Player &player, Player &opponent)
{
	_movemap[_currentMode]->action(player, opponent);
}

//returns the size of the current sprite the character is in it
sf::Vector2f State::getPlayerRectangleSize()
{
	return _movemap[_currentMode]->getPlayerRectangleSize();
}

//returns the float rectangle by according to character's current texture
sf::FloatRect State::getFloatRect(sf::Vector2f pos)
{
	return _movemap[_currentMode]->getFloatRect(pos);
}

//sets the current move to being hit (injury) - decides the new move by 
//the player's and opponent's current move
void State::setInjury(Player &injured, Player &attacker)
{

	characterSingleton::Movement newInjuryMode = _movemap[_currentMode]->getAppropriateInjuryMode(injured, attacker);
	_movemap[newInjuryMode]->set(_currentMode);
	_currentMode = newInjuryMode;

}

//returns if the character is blocking (defending)
bool State::isBlockMode() const
{
	if (_currentMode == characterSingleton::standblock || _currentMode == characterSingleton::duckblock)
	{
		return true;
	}

	return false;
}

bool State::isJumpMode() const
{
	if (_currentMode == characterSingleton::jumpkickleft ||
		_currentMode == characterSingleton::jumpkickright ||
		_currentMode == characterSingleton::jumppunchleft ||
		_currentMode == characterSingleton::jumppunchright ||
		_currentMode == characterSingleton::jumpsideLeft ||
		_currentMode == characterSingleton::jumpsideRight)
	{
		return true;
	}

	return false;
}