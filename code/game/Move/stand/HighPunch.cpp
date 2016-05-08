#include "HighPunch.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
HighPunch::HighPunch(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
HighPunch::~HighPunch()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void HighPunch::action(Player &player, Player &opponent)
{
	if (!opponent.inDuckMode())
		AttackMove::action(player, opponent);
}

//function returns true if the opponent blocks the character's attack.Else - false
bool HighPunch::checkBlock(Player &opponent)
{
	if (opponent.isStandBlock())
		return true;

	return false;
}
int HighPunch::getDamage(Player &player) const
{
	return player.getPunchPower();
}

int HighPunch::getDamageOpponentBlock(Player &player) const
{
	return player.getPunchPower() * BLOCKFACTOR;
}

void HighPunch::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::highPunch);

}