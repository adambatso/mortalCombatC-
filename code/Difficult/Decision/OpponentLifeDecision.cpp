#include "OpponentLifeDecision.h"
#include "../../game/player/Player.h"

//default constructor
OpponentLifeDecision::OpponentLifeDecision()
{
}

//get left and right decision,left if the life of the opponent above halflife else right
OpponentLifeDecision::OpponentLifeDecision(NodeDesicion leftDes, NodeDesicion rightDes)
:Decision(leftDes, rightDes)
{

}

OpponentLifeDecision::~OpponentLifeDecision()
{
}

//the function decided witch decision to return depend of the opponent's life 
Decision::NodeDesicion OpponentLifeDecision::makeDecision(Player &player, Player &opponent) const
{
	if (opponent.getLife() > HALFLIFE)
	{

		return _leftDesicion;		//opponent's life above HALFLIFE
	}
		
	else
	{
		return _rightDesicion;		//opponent's life below HALFLIFE
	}
		

	
}