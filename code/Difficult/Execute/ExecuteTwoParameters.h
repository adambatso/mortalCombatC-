#pragma once
#include "Execute.h"

/*
	this class represent and execture of action of two parameters ,
	it get the present of each parameter.
	this is an abstract class and every class that inherit from it need to implement
	the execute function that generate number and change the mode of the players according to
	the action that was chhosen.
*/
class ExecuteTwoParameters :
	public Execute
{
public:
	ExecuteTwoParameters(unsigned fisrtPrecent, unsigned secondPrecent);	//constructor that get two number each is precent of an action 
	virtual ~ExecuteTwoParameters();

	//generate number between 1 to 100 and change the mode of the players according to the action that was chhosen
	virtual void execute(Player &player, Player &opponent)  = 0;

protected:

	//the present of each action
	unsigned _firstPercentProbability,
			_secondPercentProbability;
};

