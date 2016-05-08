#pragma once
#include "Decision.h"
#include <cmath>

const int MINDJUMPISTANCE = 60; //the min distance between the player

/*
	this class represent a decision of jump,
	it check if the opponent is in distance so the player colud 
	jump and attack him .
*/
class JumpDistanceDecision :
	public Decision
{
public:
	JumpDistanceDecision();													//default constructor
	JumpDistanceDecision(NodeDesicion leftDes, NodeDesicion rightDes);		//get left and right  decision	left if the player can jump else right

	~JumpDistanceDecision();	

	NodeDesicion makeDecision(Player &player, Player &opponent) const;		//the function decided witch decision to return depend of the distance players
};

