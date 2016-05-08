#include "DifficultyEasy.h"

//default constructor call to build tree function
DifficultyEasy::DifficultyEasy()
:Difficulty()
{
	buildTree();
}


DifficultyEasy::~DifficultyEasy()
{
}

//the functoin build the map of decision and execute. and it give present for each decision.
void DifficultyEasy::buildTree()
{
	//easy Mode
	_excecuters.emplace(Decision::JumpStand, std::make_unique<JumpStand>(30, 70));
	_excecuters.emplace(Decision::JumpStandSpecial, std::make_unique<JumpStandSpecial>(30, 50, 20));
	_excecuters.emplace(Decision::GetcloserStand, std::make_unique<GetcloserStand>(40, 60));
	_excecuters.emplace(Decision::GetcloserSpecial, std::make_unique<GetcloserSpecial>(70, 30));
	_excecuters.emplace(Decision::JumpStandBackaway, std::make_unique<JumpStandBackaway>(30, 30, 40));
	_excecuters.emplace(Decision::GetcloserStandBackaway, std::make_unique<GetcloserStandBackaway>(35, 50, 15));
	_excecuters.emplace(Decision::StandBackawayDuckattack, std::make_unique<StandBackawayDuckattack>(51, 15, 34));
	_excecuters.emplace(Decision::Duckattack, std::make_unique<Duckattack>());
	_excecuters.emplace(Decision::Upperattack, std::make_unique<UpperAttack>(50));
	_excecuters.emplace(Decision::Jumpattack, std::make_unique<Jumpattack>());
	_excecuters.emplace(Decision::RandomattackStand, std::make_unique<RandomAttack>(50));
}