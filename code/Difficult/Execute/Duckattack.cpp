#include "Duckattack.h"
#include "../../game/player/Player.h"

//constructor that create the vector of attacks and give the bound too attacexecute/
Duckattack::Duckattack()
:AttackExecute(0, 2)
{
	_attack.push_back(characterSingleton::duckhighpunch);
	_attack.push_back(characterSingleton::ducklowpunch);
	_attack.push_back(characterSingleton::duckkick);
}


Duckattack::~Duckattack()
{
}
