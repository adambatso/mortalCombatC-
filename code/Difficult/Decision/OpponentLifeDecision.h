#pragma once
#include "Decision.h"

const int HALFLIFE = 50;

/*
	this class represent a decision of opponent life ,
	the class choose the left decision if the  opponent life is above HALFLIFE (a const variable)
	if his life is below HALFLIFE choose the right decision
*/
class OpponentLifeDecision :
	public Decision
{
public:
	OpponentLifeDecision();												//default constructor 
	OpponentLifeDecision(NodeDesicion leftDes, NodeDesicion rightDes);	//get left and right decision,left if the life of the opponent above halflife else right
	
	~OpponentLifeDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;	//the function decided witch decision to return depend of the opponent's life 
};

