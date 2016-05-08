#include "Ducking.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
Ducking::Ducking(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
Ducking::~Ducking()
{
}

//set function - sets all the class members to default
void Ducking::set(characterSingleton::Movement &oldMove)
{
	//dont sets as new if current move is ducking
	if (characterSingleton::ducking != oldMove &&
		oldMove != characterSingleton::duckblock &&
		oldMove != characterSingleton::duckhighpunch &&
		oldMove != characterSingleton::duckkick &&
		oldMove != characterSingleton::ducklowpunch &&
		oldMove != characterSingleton::duckbeinghit)
	{
		_animPos = 0;
		_actionMode = true;
	}

}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void Ducking::action(Player &player, Player &opponent)
{
	if (_actionMode)
	{
		//get the player down if not on the floor
		if (player.getPosition().y < GROUNDDUCK)
			player.lowerPosition(1);
		else
			_actionMode = false;

	}


}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement Ducking::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::duckbeinghitLeft;
	else
		return characterSingleton::duckbeinghitRight;
}