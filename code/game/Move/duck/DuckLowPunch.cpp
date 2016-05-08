#include "DuckLowPunch.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
DuckLowPunch::DuckLowPunch(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
DuckLowPunch::~DuckLowPunch()
{
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement DuckLowPunch::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::duckbeinghitLeft;
	else
		return characterSingleton::duckbeinghitRight;
}

//function returns true if to opponent blocks the character's attack.Else - false
bool DuckLowPunch::checkBlock(Player &opponent)
{
	if (opponent.isDuckBlock())
		return true;

	return false;
}

int DuckLowPunch::getDamage(Player &player) const
{
	return player.getPunchPower();
}

int DuckLowPunch::getDamageOpponentBlock(Player &player) const
{
	return player.getPunchPower() * BLOCKFACTOR;
}

void DuckLowPunch::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::lowPunch);

}