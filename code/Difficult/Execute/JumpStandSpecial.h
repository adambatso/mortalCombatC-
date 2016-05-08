#pragma once
#include "ExecuteThreeParameters.h"

/*
	this class represent and execture of jump/ /special ,
	this class inherit from Execute of three Parameters.
	it implement the execute fanction and change the action of the player to
	jump/stand /special action .
*/

class JumpStandSpecial :
	public ExecuteThreeParameters
{
public:
	JumpStandSpecial(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent);	//get three present one for jump and the second it to stand and threed it special.
	~JumpStandSpecial();
	void execute(Player &player, Player &opponent) ;										 //generate number and check what is the action that need to change to the players
};

