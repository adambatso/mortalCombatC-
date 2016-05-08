#pragma once
#include "../AttackMove.h"

/*
Character move class - low kick move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the check if opponent is blocking the move.
*/
class LowKick :
	public AttackMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	LowKick(std::vector <sf::Texture>& anime);

	//default d-tor
	~LowKick();

	//function returns true if the opponent blocks the character's attack.Else - false
	bool checkBlock(Player &opponent);

	int getDamage(Player &player) const;
	int getDamageOpponentBlock(Player &player) const;

	void playSoundtype() ;

};

