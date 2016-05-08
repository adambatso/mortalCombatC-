#include "StandBackawayDuckattack.h"
#include "../../game/player/Player.h"


//get three present one for stand and the second it to backAway and threed is duck attack.
StandBackawayDuckattack::StandBackawayDuckattack(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent)
:ExecuteThreeParameters(fisrtPrecent, secondPrecent, thirdPercent), _attack()
{
}


StandBackawayDuckattack::~StandBackawayDuckattack()
{
}

//generate number and check what is the action that need to change to the players
void StandBackawayDuckattack::execute(Player &player, Player &opponent) 
{
	int number = distribution(generator);

	//check stand
	if (number <= _firstPercentProbability)
	{
		player.setMove(characterSingleton::stand);
	}
	else if (_firstPercentProbability<number && number <= _secondPercentProbability + _firstPercentProbability)
	{
		//check back away
		setSideAtion(player, opponent, characterSingleton::walkingRight, characterSingleton::walkingLeft);

	}
	else
	{
		_attack.execute(player, opponent);
	}
}