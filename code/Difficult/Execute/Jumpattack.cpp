#include "Jumpattack.h"

//defult constructor
Jumpattack::Jumpattack()
:AttackExecute(0, 1)
{
	//put the jump attack to the vector 
	_attack.push_back(characterSingleton::jumpkick);
	_attack.push_back(characterSingleton::jumppunch);
}

Jumpattack::~Jumpattack()
{
}

//generate number and check witch jump to set
void Jumpattack::execute(Player &player, Player &opponent) 
{
	//generate number between the size of the attacks 
	int number = distribution(generator);


	if (_attack[number] == characterSingleton::jumpkick)
		setSideAtion(player, opponent, characterSingleton::jumpkickleft, characterSingleton::jumpkickright);
	else
		setSideAtion(player, opponent, characterSingleton::jumppunchleft, characterSingleton::jumppunchright);
}