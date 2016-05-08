#pragma once
#include "Decision.h"
#include <cmath>

/*
	this class represent a decision of distance, it have 
	variable that save the min distance.
	the class chhose the left node if the  distance between 
	tha players smaller than min distance else it chhose the right node (decision)
*/
class DistanceDecision :
	public Decision
{
public:
	DistanceDecision(int minDistance);													//constructor that get the min distance betwenn the players 
	DistanceDecision(int minDistance, NodeDesicion leftDes, NodeDesicion rightDes);		//constructor that get the min distance and also decision of the right and left 
	~DistanceDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;					//the function decided witch decision tor return depend of the distance

private:
	int _minOfDistance;		//save the min distance between the players
};

