#include "GetcloserSpecial.h"
#include "../../game/player/Player.h"
#include <iostream>

//get two present on for get coloser to opponent and the second one it to special attack
GetcloserSpecial::GetcloserSpecial(unsigned fisrtPrecent, unsigned secondPrecent)
:ExecuteTwoParameters(fisrtPrecent, secondPrecent)
{
}


GetcloserSpecial::~GetcloserSpecial()
{
}

//generate number and check what is the action that need to change to the players
void GetcloserSpecial::execute(Player &player, Player &opponent) 
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
		//set special action
		player.setMove(characterSingleton::specialAttack);
	}
}