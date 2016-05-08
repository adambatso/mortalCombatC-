#pragma once
#include "../AttackMove.h"

/*
Character move class - kick duck attack move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the attack and injury mode when hit.
*/
class DuckKick :
	public AttackMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	DuckKick(std::vector <sf::Texture>& anime);

	//default d-tor
	~DuckKick();

	//returns witch injury mode (stand/duck/jump) the character needs to be
	characterSingleton::Movement getAppropriateInjuryMode(Player &injured, Player &attacker) const;

	//function returns true if to opponent blocks the character's attack.Else - false
	bool checkBlock(Player &opponent);

	int getDamage(Player &player) const;
	int getDamageOpponentBlock(Player &player) const;

	void playSoundtype() ;

};

