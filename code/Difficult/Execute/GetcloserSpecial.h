#pragma once
#include "ExecuteTwoParameters.h"

/*
	this class represent and execture of get coloser to opponent/special attack action ,
	this class inherit from Execute of Two Parameters.
	it implement the execute fanction and change the action of the player to
	get coloser or to special attack.
*/
class GetcloserSpecial :
	public ExecuteTwoParameters
{
public:
	GetcloserSpecial(unsigned fisrtPrecent, unsigned secondPrecent);	//get two present on for get coloser to opponent and the second one it to special attack
	~GetcloserSpecial();
	
	void execute(Player &player, Player &opponent) ;					//generate number and check what is the action that need to change to the players
			
};

