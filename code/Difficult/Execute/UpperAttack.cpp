#include "UpperAttack.h"
#include "../../game/player/Player.h"

//constructor that get present of probability to stand (the rest go to attack) 
UpperAttack::UpperAttack(int standProbability)
:AttackExecute(0, 3), _standProbability(standProbability)
{

	//add all the stand attacks 
	_attack.push_back(characterSingleton::highpunch);
	_attack.push_back(characterSingleton::lowpunch);
	_attack.push_back(characterSingleton::highkick);
	_attack.push_back(characterSingleton::lowkick);
}


UpperAttack::~UpperAttack()
{
}

//generate number and check witch attack to set (or stand)
void UpperAttack::execute(Player &player, Player &opponent)
{
	std::uniform_int_distribution<int> distribution1(1,100);
	
	int number = distribution1(generator);

	//check if the number is in stand range if not i generate attack to set
	if (number <= _standProbability)
		player.setMove(characterSingleton::stand);
	else
		AttackExecute::execute(player, opponent);
}