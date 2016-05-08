#pragma once
#include "../AttackMove.h"
/*
Character move class - high kick move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the attack and checks if opponent is blocking the move.
*/
class HighKick :
	public AttackMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	HighKick(std::vector <sf::Texture>& anime);

	//default d-tor
	~HighKick();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);

	//function returns true if the opponent blocks the character's attack.Else - false
	bool checkBlock(Player &opponent);

	int getDamage(Player &player) const;
	int getDamageOpponentBlock(Player &player) const;
	void playSoundtype();

};

