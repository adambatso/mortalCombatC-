#include "DistanceDecision.h"
#include "../../game/player/Player.h"
#include <iostream>

//constructor that get the min distance betwenn the players 
DistanceDecision::DistanceDecision(int minDistance)
:_minOfDistance(minDistance)
{
}

//constructor that get the min distance and also decision of the right and left 
DistanceDecision::DistanceDecision(int minDistance, NodeDesicion leftDes, NodeDesicion rightDes)
: Decision(leftDes, rightDes), _minOfDistance(minDistance)
{
}

DistanceDecision::~DistanceDecision()
{
}

// the function decided witch decision tor return depend of the distance
Decision::NodeDesicion DistanceDecision::makeDecision(Player &player, Player &opponent) const
{

	//it check if the distance between the players is smaller/bigger then min distance
	if (std::abs(player.getPosition().x - opponent.getPosition().x) < _minOfDistance)
	{
		return _rightDesicion;				//opponent close
	}
		
	else
	{
		return _leftDesicion;				//opponent far
	}
		
}