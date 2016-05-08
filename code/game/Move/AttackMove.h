#pragma once
#include "Move.h"

const double BLOCKFACTOR = 0.5;

/*
Character move class - attack move.
Abstract class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for the attack moves who inherits from it.
*/
class AttackMove :
	virtual public Move
{
public:
	//c-tor - arguments: anime - vector that holds the move sprites
	AttackMove(std::vector <sf::Texture>& anime);

	//default d-tor
	virtual ~AttackMove();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	virtual void action(Player &player, Player &opponent);

	//returns if the current status of the character's move is changeable
	virtual bool changeable() const;

	//updates to appropriate image in the texture's vector
	virtual void nextFrame();

	//set function - sets all the class members to default
	void set(characterSingleton::Movement &oldMove);

	//function returns true if there is a collision between the character to its opponent
	//else - return false
	virtual bool checkIfCollision(Player &player, Player &opponent);

	//function returns true if to opponent blocks the character's attack.Else - false
	virtual bool checkBlock(Player &opponent) = 0;

	virtual int getDamage(Player &player) const=0;
	virtual int getDamageOpponentBlock(Player &player) const=0;

	virtual void playSoundtype() = 0;

protected:
	bool _forwardFrame = true;

};

