#include "JumpStandSpecial.h"
#include "../../game/player/Player.h"

//get three present one for jump and the second it to stand and threed it special.
JumpStandSpecial::JumpStandSpecial(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent)
:ExecuteThreeParameters(fisrtPrecent, secondPrecent, thirdPercent)
{
}


JumpStandSpecial::~JumpStandSpecial()
{
}

//generate number and check what is the action that need to change to the players
void JumpStandSpecial::execute(Player &player, Player &opponent) 
{
	int number = distribution(generator);

	if (number <= _firstPercentProbability)
	{
		setSideAtion(player, opponent, characterSingleton::jumpsideLeft, characterSingleton::jumpsideRight);
	}
	else if (_firstPercentProbability<number && number <= _secondPercentProbability + _firstPercentProbability)
	{
		player.setMove(characterSingleton::stand);
	}
	else
	{
		//special move
		player.setMove(characterSingleton::specialAttack);
	}
}