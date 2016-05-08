#include "OpponentBlockDecision.h"
#include "../../game/player/Player.h"

//default constructor 
OpponentBlockDecision::OpponentBlockDecision()
{
}

//get left and right  decision	left if the player block else right
OpponentBlockDecision::OpponentBlockDecision(NodeDesicion leftDes, NodeDesicion rightDes)
:Decision(leftDes, rightDes)
{

}


OpponentBlockDecision::~OpponentBlockDecision()
{
}

//the function decided witch decision to return depend of the opponent mode
Decision::NodeDesicion OpponentBlockDecision::makeDecision(Player &player, Player &opponent) const
{

	characterSingleton::Movement opponentCurrMode = opponent.getCurrentMode();
	
	//check if the opponentblock 
	if (opponentCurrMode == characterSingleton::duckblock ||
		opponentCurrMode == characterSingleton::standblock)
	{

		return _leftDesicion;		//opponent block
	}
	else
	{

		return _rightDesicion;		//opponent not in block mode
	}

}