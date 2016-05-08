#include "JumpDecision.h"
#include "../../game/player/Player.h"

//default constructor
JumpDecision::JumpDecision()
{
}

//get left and right  decision	left to opponent jump and right else
JumpDecision::JumpDecision(NodeDesicion leftDes, NodeDesicion rightDes)
:Decision(leftDes, rightDes)
{

}


JumpDecision::~JumpDecision()
{
}

//the function decided witch decision to return depend of the opponent mode (if it jump or not)
Decision::NodeDesicion JumpDecision::makeDecision(Player &player, Player &opponent) const
{
	
	

	if (opponent.isJumpMode())
	{

		return _leftDesicion;
	}
	else
	{
		return _rightDesicion;
	}
}