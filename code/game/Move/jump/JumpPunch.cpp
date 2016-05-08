#include "JumpPunch.h"
#include "../../Player/Player.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
JumpPunch::JumpPunch(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
: Move(anime), MovePosition(anime, offset, direction), JumpMove(anime, offset, direction), AttackMove(anime)
{
}

//default d-tor
JumpPunch::~JumpPunch()
{
}

//set function - sets all the class members to default
void JumpPunch::set(characterSingleton::Movement &oldMove)
{
	_up = false;
	_hit = false;
	MovePosition::set(oldMove);
}

//updates to appropriate image in the texture's vector
void JumpPunch::nextFrame()
{
	Move::nextFrame();
}

//returns if the current status of the character's move is changeable
bool JumpPunch::changeable() const
{
	return false;
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void JumpPunch::action(Player &player, Player &opponent)
{
	JumpMove::action(player, opponent);

	if (!_hit)
	{
		if (checkIfCollision(player, opponent))
		{
			_hit = true;

			if (checkBlock(opponent))				//oppnent is blocking
				opponent.decreaseLife(getDamageOpponentBlock(player));
			else
				opponent.setInjury(getDamage(player), player);		//oppnent not blocking

			std::cout << opponent.getLife() << std::endl;

			playSoundtype();
		}
	}
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement JumpPunch::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	return JumpMove::getAppropriateInjuryMode(injured, attacker);
}

//function returns true if the opponent blocks the character's attack.Else - false
bool JumpPunch::checkBlock(Player &opponent)
{
	if (opponent.isGneralBlock())
		return true;

	return false;
}

int JumpPunch::getDamage(Player &player) const
{
	return player.getPunchPower() * 1.2;
}

int JumpPunch::getDamageOpponentBlock(Player &player) const
{
	return player.getPunchPower() * BLOCKFACTOR;
}

void JumpPunch::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::highPunch);

}