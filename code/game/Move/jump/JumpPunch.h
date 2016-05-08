#pragma once
#include "JumpMove.h"
#include "../AttackMove.h"

/*
Character move class - kick kick move.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the attack,set,next frame,if changeable, and injury mode if hit.
*/
class JumpPunch :
	public JumpMove, public AttackMove
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	JumpPunch(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	~JumpPunch();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	void action(Player &player, Player &opponent);

	//set function - sets all the class members to default
	void set(characterSingleton::Movement &oldMove);

	//updates to appropriate image in the texture's vector
	void nextFrame();

	//returns if the current status of the character's move is changeable
	bool changeable() const;

	//returns witch injury mode (stand/duck/jump) the character needs to be
	characterSingleton::Movement getAppropriateInjuryMode(Player &injured, Player &attacker) const;

	//function returns true if the opponent blocks the character's attack.Else - false
	bool checkBlock(Player &opponent);

	int getDamage(Player &player) const;
	int getDamageOpponentBlock(Player &player) const;

	void playSoundtype() ;


private:
	bool _hit = false;		//if the character hit opponent
};

