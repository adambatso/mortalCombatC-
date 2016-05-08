#include "JumpDistanceDecision.h"
#include "../../game/player/Player.h"

//default constructor
JumpDistanceDecision::JumpDistanceDecision()
{
}

//get left and right  decision	left if the player can jump else right
JumpDistanceDecision::JumpDistanceDecision(NodeDesicion leftDes, NodeDesicion rightDes)
:Decision(leftDes,rightDes)
{
}
JumpDistanceDecision::~JumpDistanceDecision()
{
}

//the function decided witch decision to return depend of the distance players
Decision::NodeDesicion JumpDistanceDecision::makeDecision(Player &player, Player &opponent) const
{
	if (std::abs(player.getPosition().x - opponent.getPosition().x) < MINDJUMPISTANCE)
	{

		return _leftDesicion;				//opponent in jump distance
	}
	
	else
	{

		return _rightDesicion;				//opponent not in jump distance
	}
	
}