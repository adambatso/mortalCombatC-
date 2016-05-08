#include "HighKick.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
HighKick::HighKick(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime)
{
}

//default d-tor
HighKick::~HighKick()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void HighKick::action(Player &player, Player &opponent)
{
	if (!opponent.inDuckMode())
		AttackMove::action(player, opponent);
}

//function returns true if the opponent blocks the character's attack.Else - false
bool HighKick::checkBlock(Player &opponent)
{
	if (opponent.isStandBlock())
		return true;

	return false;
}

int HighKick::getDamage(Player &player) const
{
	return player.getKickPower();
}

int HighKick::getDamageOpponentBlock(Player &player) const
{
	return player.getKickPower() * BLOCKFACTOR;
}

void HighKick::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::highKick);

}