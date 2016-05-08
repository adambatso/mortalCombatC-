#pragma once
#include "Execute.h"

/*
	this class represent attack execute it inherit from execute and implament the execute function.
	this calls have protected vectors (for class that inherit from it will crate the vector) 
	of attack and it generate attack from the bound that is get.
*/
class AttackExecute :
	public Execute
{
public:
	AttackExecute(int lowBound, int highBound);					//constructor that get 2 integers (low and high bounds) and build attack execute
	virtual ~AttackExecute();									//default destructor
	virtual void execute(Player &player, Player &opponent);		//get two player and set the right state for them (it generate attack )
	

protected:
	std::vector<characterSingleton::Movement> _attack;			//vector of attack move all the classed that inherit from them create the vector
};

