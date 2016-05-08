#pragma once
#include "Decision.h"

/*
	this class represent a decision of opponent jump,
	it check if the opponent is in jump mode  and return the 
	keft node else it return the right decision.
*/
class JumpDecision :
	public Decision
{
public:
	JumpDecision();													//default constructor
	JumpDecision(NodeDesicion leftDes, NodeDesicion rightDes);		//get left and right  decision	left to opponent jump and right else
	~JumpDecision();

	NodeDesicion makeDecision(Player &player, Player &opponent) const;		//the function decided witch decision to return depend of the opponent mode (if it jump or not)
};

