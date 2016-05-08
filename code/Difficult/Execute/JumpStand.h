#pragma once
#include "ExecuteTwoParameters.h"

/*
	this class represent and execture of jump/stand action ,
	this class inherit from Execute of Two Parameters.
	it implement the execute fanction and change the action of the player to
	get coloser or to stand.
*/
class JumpStand :
	public ExecuteTwoParameters
{
public:
	JumpStand(unsigned fisrtPrecent, unsigned secondPrecent); //get two present one for get coloser to opponent and the second one it to stand
	~JumpStand();

	void execute(Player &player, Player &opponent) ;		 //generate number and check what is the action that need to change to the players
};

