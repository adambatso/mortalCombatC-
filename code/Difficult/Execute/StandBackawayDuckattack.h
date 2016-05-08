#pragma once
#include "ExecuteThreeParameters.h"
#include "Duckattack.h"


/*
	this class represent and execture of stand/backAway/duck attack action ,
	this class inherit from Execute of three Parameters.
	it implement the execute fanction and change the action of the player to
	stand/backAway/duck attack action .
*/
class StandBackawayDuckattack :
	public ExecuteThreeParameters
{
public:
	StandBackawayDuckattack(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent);	//get three present one for stand and the second it to backAway and threed is duck attack.
	~StandBackawayDuckattack();
	void execute(Player &player, Player &opponent) ;												//generate number and check what is the action that need to change to the players


private:
	Duckattack _attack;
};

