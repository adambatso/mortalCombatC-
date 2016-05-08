#include "OpponentDuckDecision.h"
#include "../../game/player/Player.h"

//default constructor 
OpponentDuckDecision::OpponentDuckDecision()
{
}

//get left and right  decision,left if the player duck else right
OpponentDuckDecision::OpponentDuckDecision(NodeDesicion leftDes, NodeDesicion rightDes)
:Decision(leftDes,rightDes)
{
}

OpponentDuckDecision::~OpponentDuckDecision()
{
}


//the function decided witch decision to return depend of the opponent mode
Decision::NodeDesicion OpponentDuckDecision::makeDecision(Player &player, Player &opponent) const
{
	characterSingleton::Movement opponentCurrMode = opponent.getCurrentMode();

	//check if the opponent in duck mode 
	if (opponentCurrMode == characterSingleton::ducking ||
		opponentCurrMode == characterSingleton::duckbeinghitLeft ||
		opponentCurrMode == characterSingleton::duckbeinghitRight ||
		opponentCurrMode == characterSingleton::duckblock)
	{

		return _leftDesicion;			//opponent duck
	}
	else
	{

		return _rightDesicion;			//opponent not in duck mode
	}

}