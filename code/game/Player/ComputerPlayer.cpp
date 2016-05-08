#include "ComputerPlayer.h"

//c-tor - arguments: nameOfCharacter - in order to load the appropriate textures
ComputerPlayer::ComputerPlayer(charName nameOfCharacter, Difficulty::Difficult gameNum)
:Player(sf::Vector2f(450,450),nameOfCharacter)
{
	switch (gameNum)
	{
	case Difficulty::easy:
		_difficulty = std::make_unique<DifficultyEasy>();
		break;
	case Difficulty::medium:
		_difficulty = std::make_unique<DifficultyMedium>();
		break;
	case Difficulty::hard:
		_difficulty = std::make_unique<DifficultyHard>();
		break;
	default:
		break;
	}
}

//default d-tor
ComputerPlayer::~ComputerPlayer()
{
}

//function updates character's move by object's decision tree.
//opponent - to update if neseccery
void ComputerPlayer::makeDecision(Player & opponent)
{
	//check if character is blocking and react appropriatly
	if (_state.isBlockMode())
	{
		if (!_fisrtTimeBlock)
		{
			_clBlock.restart();
			_fisrtTimeBlock = true;
		}
	}

	//update that can block again
	if (_clBlock.getElapsedTime().asSeconds() > 1)
		_fisrtTimeBlock = false;

	//if user is not blocking make decision
	if (!_fisrtTimeBlock)
	{
		_difficulty->makeDecision(*this, opponent);
		
		if (_state.isDuckMode())
		{
			if (!_fisrtTimeDuck)
			{
				_fisrtTimeDuck = true;
				_position.y = GROUNDDUCK;
			}
		}
		else
		{
			if (_fisrtTimeDuck)
			{
				_fisrtTimeDuck = false;
				_position.y = GROUNDSTAND;
			}
		}
	}


		
}

//returns if character is standing and blocking
bool ComputerPlayer::isStandBlock() 
{
	if (!_state.isJumpMode())
	{
		if (_difficulty->DrawBlock())
		{
			setMove(characterSingleton::standblock);
			return true;
		}

	}
	
	return false;
}

//returns if character is ducking and blocking
bool ComputerPlayer::isDuckBlock() 
{
	if (!_state.isJumpMode())
	{
		if (_difficulty->DrawBlock())
		{
			setMove(characterSingleton::duckblock);
			return true;
		}
	}
	return false;
}

//returns if character is blocking (ducking/standing)
bool ComputerPlayer::isGneralBlock() 
{
	if (!_state.isJumpMode())
	{
		if (_difficulty->DrawBlock())
		{
			setMove(characterSingleton::standblock);
			return true;
		}
	}

	return false;
}