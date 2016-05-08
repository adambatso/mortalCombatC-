#include "DuckKick.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
DuckKick::DuckKick(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
DuckKick::~DuckKick()
{
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement DuckKick::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::duckbeinghitLeft;
	else
		return characterSingleton::duckbeinghitRight;
}

//function returns true if to opponent blocks the character's attack.Else - false
bool DuckKick::checkBlock(Player &opponent)
{
	if (opponent.isDuckBlock())
		return true;

	return false;
}

int DuckKick::getDamage(Player &player) const
{
	return player.getKickPower();
}

int DuckKick::getDamageOpponentBlock(Player &player) const
{
	return player.getKickPower() * BLOCKFACTOR;
}

void DuckKick::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::lowKick);

}