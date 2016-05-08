#include "JumpStandBackaway.h"
#include "../../game/player/Player.h"
#include <iostream>

//get three present one for jump and the second it to stand and threed is backAway.
JumpStandBackaway::JumpStandBackaway(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent)
:ExecuteThreeParameters(fisrtPrecent, secondPrecent, thirdPercent)
{
}


JumpStandBackaway::~JumpStandBackaway()
{
}

//generate number and check what is the action that need to change to the players
void JumpStandBackaway::execute(Player &player, Player &opponent) 
{
	int number = distribution(generator);

	//check jump
	if ( number <= _firstPercentProbability)
	{
		setSideAtion(player, opponent, characterSingleton::jumpsideLeft, characterSingleton::jumpsideRight);
	}
	//check stand
	else if (_firstPercentProbability<number && number <= _secondPercentProbability + _firstPercentProbability)
	{
		player.setMove(characterSingleton::stand);
	}
	//check backaway
	else
	{
		setSideAtion(player, opponent, characterSingleton::walkingRight, characterSingleton::walkingLeft);
		
	}
}