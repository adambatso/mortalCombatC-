#include "JumpStand.h"
#include "../../game/player/Player.h"

//get two present one for get coloser to opponent and the second one it to stand
JumpStand::JumpStand(unsigned fisrtPrecent, unsigned secondPrecent)
:ExecuteTwoParameters(fisrtPrecent, secondPrecent)
{
}


JumpStand::~JumpStand()
{
}

//generate number and check what is the action that need to change to the players
void JumpStand::execute(Player &player, Player &opponent) 
{

	//generate number
	int number = distribution(generator);
	
	//check if the number is in the range of the first action 
	if (0 < number && number <= _firstPercentProbability)
	{
		setSideAtion(player, opponent, characterSingleton::jumpsideLeft, characterSingleton::jumpsideRight);

	}
	else
	{
		player.setMove(characterSingleton::stand);
	}
}