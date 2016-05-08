#include "AttackExecute.h"
#include "../../game/Player/Player.h"

//constructor that get 2 integers (low and high bounds) and build attack execute
AttackExecute::AttackExecute(int lowBound, int highBound)
:Execute(lowBound, highBound)
{
}

//default destructor
AttackExecute::~AttackExecute()
{
}

//get two player and set the right state for them (it generate attack )
void AttackExecute::execute(Player &player, Player &opponent) 
{
	int number = distribution(generator);

	player.setMove(_attack[number]);
}