#include "DifficultyMedium.h"

//default constructor call to build tree function
DifficultyMedium::DifficultyMedium()
:Difficulty()
{
	buildTree();
}


DifficultyMedium::~DifficultyMedium()
{
}

//the functoin build the map of decision and execute. and it give present for each decision.
void DifficultyMedium::buildTree()
{
	//medium Mode
	_excecuters.emplace(Decision::JumpStand, std::make_unique<JumpStand>(40, 60));
	_excecuters.emplace(Decision::JumpStandSpecial, std::make_unique<JumpStandSpecial>(40, 30, 30));
	_excecuters.emplace(Decision::GetcloserStand, std::make_unique<GetcloserStand>(55, 45));
	_excecuters.emplace(Decision::GetcloserSpecial, std::make_unique<GetcloserSpecial>(70, 30));
	_excecuters.emplace(Decision::JumpStandBackaway, std::make_unique<JumpStandBackaway>(40, 35, 25));
	_excecuters.emplace(Decision::GetcloserStandBackaway, std::make_unique<GetcloserStandBackaway>(45, 40, 15));
	_excecuters.emplace(Decision::StandBackawayDuckattack, std::make_unique<StandBackawayDuckattack>(40, 15, 45));
	_excecuters.emplace(Decision::Duckattack, std::make_unique<Duckattack>());
	_excecuters.emplace(Decision::Upperattack, std::make_unique<UpperAttack>(40));
	_excecuters.emplace(Decision::Jumpattack, std::make_unique<Jumpattack>());
	_excecuters.emplace(Decision::RandomattackStand, std::make_unique<RandomAttack>(40));
}