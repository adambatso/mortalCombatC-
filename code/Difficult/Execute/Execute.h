#pragma once
#include <random>
#include <chrono>
#include "../../singleton/characterSingleton.h"
class Player;


/*
	this class represent and execture of decition , this class is abstract class 
	and it have virtual function that get two players and change them differently
	between all the class that inherit. 
*/
class Execute
{
public:
	Execute(int lowBound = 1, int highBound = 100);	//get two paramenter that dedided what will be the range of the numbers that will generate randomly and will affact of the execute
	virtual ~Execute();								//default destructor
			
	virtual void execute(Player &player, Player &opponent) =0;	//virtual function that get player and opponent  

protected:
	std::default_random_engine generator;				//this variable is used to generate random number
	std::uniform_int_distribution<int> distribution;

	void setSideAtion(Player &player, Player &opponent, const characterSingleton::Movement left, const characterSingleton::Movement right) const; //the function get to player and decided what is the direction of the movement depend on the opponent
};

