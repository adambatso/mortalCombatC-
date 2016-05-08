#pragma once
#include "AttackExecute.h"

/*
	this class represent and execture of jump attack 
	this class inherit from AttackExecute.
	it implement the execute fanction and change the action of the player to
	get jump attack (punch or kick)
*/
class Jumpattack :
	public AttackExecute
{
public:
	Jumpattack();										//defult constructor 
	~Jumpattack();
	void execute(Player &player, Player &opponent) ;	//generate number and check witch jump to set

};

