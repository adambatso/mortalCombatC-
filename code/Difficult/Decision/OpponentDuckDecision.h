#pragma once
#include "Decision.h"

/*
	this class represent a decision of opponent duck mode,
	the class chhose the left decision if the  opponent is in duck mode 
	if he is not it choose the right decision.
*/
class OpponentDuckDecision :
	public Decision
{
public:
	OpponentDuckDecision();													//default constructor 
	OpponentDuckDecision(NodeDesicion leftDes, NodeDesicion rightDes);		//get left and right  decision,left if the player duck else right

	~OpponentDuckDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;		//the function decided witch decision to return depend of the opponent mode
};

