#include "DifficultyHard.h"

//default constructor call to build tree function
DifficultyHard::DifficultyHard()
:Difficulty()
{
	buildTree();
}


DifficultyHard::~DifficultyHard()
{
}

//the functoin build the map of decision and execute. and it give present for each decision.
void DifficultyHard::buildTree()
{
	//hard Mode
	_excecuters.emplace(Decision::JumpStand, std::make_unique<JumpStand>(50, 50));
	_excecuters.emplace(Decision::JumpStandSpecial, std::make_unique<JumpStandSpecial>(35, 25, 40));
	_excecuters.emplace(Decision::GetcloserStand, std::make_unique<GetcloserStand>(70, 30));
	_excecuters.emplace(Decision::GetcloserSpecial, std::make_unique<GetcloserSpecial>(55, 45));
	_excecuters.emplace(Decision::JumpStandBackaway, std::make_unique<JumpStandBackaway>(55, 25, 20));
	_excecuters.emplace(Decision::GetcloserStandBackaway, std::make_unique<GetcloserStandBackaway>(45, 40, 15));
	_excecuters.emplace(Decision::StandBackawayDuckattack, std::make_unique<StandBackawayDuckattack>(25, 15, 60));
	_excecuters.emplace(Decision::Duckattack, std::make_unique<Duckattack>());
	_excecuters.emplace(Decision::Upperattack, std::make_unique<UpperAttack>(30));
	_excecuters.emplace(Decision::Jumpattack, std::make_unique<Jumpattack>());
	_excecuters.emplace(Decision::RandomattackStand, std::make_unique<RandomAttack>(30));
}