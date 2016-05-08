#pragma once
#include "Decision.h"


/*
	this class represent a decision of opponent block mode,
	the class chhose the left decision if the  opponent is in block mode (stand/duck)
	if he is not it choose the right decision 
*/
class OpponentBlockDecision :
	public Decision
{
public:
	OpponentBlockDecision();													//default constructor 
	OpponentBlockDecision(NodeDesicion leftDes, NodeDesicion rightDes);			//get left and right  decision	left if the player block else right
	~OpponentBlockDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;			//the function decided witch decision to return depend of the opponent mode
};

