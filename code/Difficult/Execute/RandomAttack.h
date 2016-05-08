#pragma once
#include "AttackExecute.h"

/*
this class represent and execture of random attack
random attack can be any attack except of jump attack
this class inherit from AttackExecute.
it implement the execute fanction and change the action of the player to
a random attack
*/
class RandomAttack :
	public AttackExecute
{
public:
	RandomAttack(int standProbability);				//constructor that get present of probability to stand (the rest go to attack) 
	~RandomAttack();

	void execute(Player &player, Player &opponent);	//generate number and check witch attack to set (or stand)

private:
	int _standProbability;
};

