#pragma once
#include "AttackExecute.h"

/*
	this class represent and execture of stand attack
	this class inherit from AttackExecute.
	it implement the execute fanction and change the action of the player to
	get stand attack (punch or kick /high or low)
*/
class UpperAttack :
	public AttackExecute
{
public:
	UpperAttack(int standProbability);					//constructor that get present of probability to stand (the rest go to attack) 
	~UpperAttack();
	void execute(Player &player, Player &opponent);		//generate number and check witch attack to set (or stand)

private:
	int _standProbability;

};

