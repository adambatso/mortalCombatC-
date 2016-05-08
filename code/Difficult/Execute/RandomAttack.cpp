#include "RandomAttack.h"
#include "../../game/player/Player.h"

//constructor that get present of probability to stand (the rest go to attack) 
RandomAttack::RandomAttack(int standProbability)
:AttackExecute(0, 6), _standProbability(standProbability)
{
	//add all the attack to the attacks vector 
	_attack.push_back(characterSingleton::duckhighpunch);
	_attack.push_back(characterSingleton::ducklowpunch);
	_attack.push_back(characterSingleton::duckkick);
	_attack.push_back(characterSingleton::highpunch);
	_attack.push_back(characterSingleton::lowpunch);
	_attack.push_back(characterSingleton::highkick);
	_attack.push_back(characterSingleton::lowkick);
	_attack.push_back(characterSingleton::specialAttack);
}



RandomAttack::~RandomAttack()
{
}

//generate number and check witch attack to set (or stand)
void RandomAttack::execute(Player &player, Player &opponent)
{

	std::uniform_int_distribution<int> distribution1(1, 100);

	int number = distribution1(generator);

	//check if it in stand range else it generate attack
	if (number <= _standProbability)
		player.setMove(characterSingleton::stand);
	else
		AttackExecute::execute(player, opponent);
}