#include "LowKick.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
LowKick::LowKick(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
LowKick::~LowKick()
{
}

//function returns true if the opponent blocks the character's attack.Else - false
bool LowKick::checkBlock(Player &opponent)
{
	if (opponent.isStandBlock())
		return true;

	return false;
}

int LowKick::getDamage(Player &player) const
{
	return player.getKickPower();
}

int LowKick::getDamageOpponentBlock(Player &player) const
{
	return player.getKickPower() * BLOCKFACTOR;
}

void LowKick::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::lowKick);

}