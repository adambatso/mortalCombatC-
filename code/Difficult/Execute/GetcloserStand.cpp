#include "GetcloserStand.h"
#include "../../game/player/Player.h"

//get two present one for get coloser to opponent and the second one it to stand
GetcloserStand::GetcloserStand(unsigned fisrtPrecent, unsigned secondPrecent)
:ExecuteTwoParameters(fisrtPrecent, secondPrecent)
{
}


GetcloserStand::~GetcloserStand()
{
}

//generate number and check what is the action that need to change to the players
void GetcloserStand::execute(Player &player, Player &opponent) 
{

	//generate number
	int number = distribution(generator);

	//check if the number is in the range of the first action 
	if (number <= _firstPercentProbability)
	{
		//set walking to the right direction 
		setSideAtion(player, opponent, characterSingleton::walkingLeft, characterSingleton::walkingRight);

	}
	else
	{
		//set stand
		player.setMove(characterSingleton::stand);
	}
}