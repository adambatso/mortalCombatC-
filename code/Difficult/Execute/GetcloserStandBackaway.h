#pragma once
#include "ExecuteThreeParameters.h"

/*
	this class represent and execture of get coloser to opponent/stand /backAway action ,
	this class inherit from Execute of three Parameters.
	it implement the execute fanction and change the action of the player to
	get coloser or to stand.
*/
class GetcloserStandBackaway :
	public ExecuteThreeParameters
{
public:

	GetcloserStandBackaway(unsigned fisrtPrecent, unsigned secondPrecent, unsigned thirdPercent); //get three present one for get coloser to opponent and the second one it to stand and threed is backAway.
	~GetcloserStandBackaway();
	void execute(Player &player, Player &opponent) ;											  //generate number and check what is the action that need to change to the players

};

