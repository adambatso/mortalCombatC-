#include "JumpKick.h"
#include "../../Player/Player.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
JumpKick::JumpKick(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
: Move(anime), MovePosition(anime, offset, direction), JumpMove(anime, offset, direction), AttackMove(anime)
{
}

//default d-tor
JumpKick::~JumpKick()
{
}

//set function - sets all the class members to default
void JumpKick::set(characterSingleton::Movement &oldMove)
{
	_up = false;
	_hit = false;
	MovePosition::set(oldMove);
}

//updates to appropriate image in the texture's vector
void JumpKick::nextFrame()
{
	Move::nextFrame();
}

//returns if the current status of the character's move is changeable
bool JumpKick::changeable() const
{
	return false;
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void JumpKick::action(Player &player, Player &opponent)
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
characterSingleton::Movement JumpKick::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	return JumpMove::getAppropriateInjuryMode(injured, attacker);
}

//function returns true if to opponent blocks the character's attack.Else - false
bool JumpKick::checkBlock(Player &opponent)
{
	if (opponent.isGneralBlock())
		return true;

	return false;
}

int JumpKick::getDamage(Player &player) const
{
	return player.getKickPower() * 1.2; 
}

int JumpKick::getDamageOpponentBlock(Player &player) const
{
	return player.getKickPower() * BLOCKFACTOR;
}

void JumpKick::playSoundtype() 
{
	GeneralSingleton::instance().playSound(GeneralSingleton::highKick);

}