#include "OpponentStandDecision.h"
#include "../../game/player/Player.h"

OpponentStandDecision::OpponentStandDecision()
{
}


OpponentStandDecision::~OpponentStandDecision()
{
}

Decision::NodeDesicion OpponentStandDecision::makeDecision(Player &player, Player &opponent) const
{
	characterSingleton::Movement opponentCurrMode = opponent.getCurrentMode();

	//if opponent is in stand mode
	if (opponentCurrMode == characterSingleton::stand ||
		opponentCurrMode == characterSingleton::standblock ||
		opponentCurrMode == characterSingleton::standbeinghitLeft ||
		opponentCurrMode == characterSingleton::standbeinghitRight ||
		opponentCurrMode == characterSingleton::walkingLeft ||
		opponentCurrMode == characterSingleton::walkingRight  )
	{
		return _leftDesicion;		//opponent stand mode
	}
	else
	{
		return _rightDesicion;		//opponent not in stand mode
	}
}