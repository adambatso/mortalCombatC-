#include "GetcloserStandBackaway.h"
#include "../../game/player/Player.h"
#include <iostream>

//get three present one for get coloser to opponent and the second one it to stand and threed is backAway.
GetcloserStandBackaway::GetcloserStandBackaway(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent)
:ExecuteThreeParameters(fisrtPrecent, secondPrecent, thirdPercent)
{
}


GetcloserStandBackaway::~GetcloserStandBackaway()
{
}

//generate number and check what is the action that need to change to the players
void GetcloserStandBackaway::execute(Player &player, Player &opponent) 
{
	//generate number
	int number = distribution(generator);

	//check get closer
	if (number <= _firstPercentProbability)
	{
		setSideAtion(player, opponent, characterSingleton::walkingLeft, characterSingleton::walkingRight);
	}
	//check stand
	else if (_firstPercentProbability<number && number <= _secondPercentProbability + _firstPercentProbability)
	{
		player.setMove(characterSingleton::stand);
	}
	//check back away
	else
	{
		setSideAtion(player, opponent, characterSingleton::walkingRight, characterSingleton::walkingLeft);
	}
}