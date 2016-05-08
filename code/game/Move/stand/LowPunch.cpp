#include "LowPunch.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
LowPunch::LowPunch(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
LowPunch::~LowPunch()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void LowPunch::action(Player &player, Player &opponent)
{
	if (!opponent.inDuckMode())
		AttackMove::action(player, opponent);
}

//function returns true if the opponent blocks the character's attack.Else - false
bool LowPunch::checkBlock(Player &opponent)
{
	if (opponent.isStandBlock())
		return true;

	return false;
}

int LowPunch::getDamage(Player &player) const
{
	return player.getPunchPower();
}

int LowPunch::getDamageOpponentBlock(Player &player) const
{
	return player.getPunchPower() * BLOCKFACTOR;
}

void LowPunch::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::lowPunch);

}