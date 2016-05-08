#pragma once
#include "AttackExecute.h"

/*
	this class represent duck attack and it inherit from attack execute,
	it build the vector of attacks (it put all duck attack) and gie the bounds to attackexecute class.
*/
class Duckattack :
	public AttackExecute
{
public:
	Duckattack();
	~Duckattack();
	

};

