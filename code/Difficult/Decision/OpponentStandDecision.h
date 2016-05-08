#pragma once
#include "Decision.h"

/*
this class represent a decision of opponent stand mode,
the class chhose the left decision if the  opponent is in stand mode
if he is not it choose the right decision.
*/
class OpponentStandDecision :
	public Decision
{
public:
	OpponentStandDecision();							//default constructor
	~OpponentStandDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;		//the function decided witch decision to return depend of the opponent mode
};

