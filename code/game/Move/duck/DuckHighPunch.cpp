#include "DuckHighPunch.h"
#include "../../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
DuckHighPunch::DuckHighPunch(std::vector <sf::Texture>& anime)
:Move(anime), AttackMove(anime), _distribution(1,100)
{
	//give seed to the generator
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	_generator.seed(seed);
}

//default d-tor
DuckHighPunch::~DuckHighPunch()
{
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement DuckHighPunch::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::duckbeinghitLeft;
	else
		return characterSingleton::duckbeinghitRight;
}

//function returns true if to opponent blocks the character's attack.Else - false
bool DuckHighPunch::checkBlock(Player &opponent)
{
	if (opponent.isDuckBlock())
		return true;

	return false;
}

int DuckHighPunch::getDamage(Player &player) const
{
	return player.getPunchPower() * 1.3;
}

int DuckHighPunch::getDamageOpponentBlock(Player &player) const
{
	return player.getPunchPower() * BLOCKFACTOR;
}

void DuckHighPunch::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::highPunch);
	
	int number = _distribution(_generator);

	if (number<30)
		GeneralSingleton::instance().playSound(GeneralSingleton::danforden);

}