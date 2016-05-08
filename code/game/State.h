#pragma once

#include <map>
#include <memory>
#include "../singleton/characterSingleton.h"
#include "Move/stand/LowKick.h"
#include "Move/stand/Stand.h"
#include "Move/stand/Walking.h"
#include "Move/stand/HighKick.h"
#include "Move/stand/HighPunch.h"
#include "Move/stand/LowPunch.h"
#include "Move/duck/DuckBlock.h"
#include "Move/duck/DuckHighPunch.h"
#include "Move/duck/Ducking.h"
#include "Move/duck/DuckKick.h"
#include "Move/duck/DuckLowPunch.h"
#include "Move/jump/JumpKick.h"
#include "Move/jump/JumpPunch.h"
#include "Move/jump/JumpSide.h"
#include "Move/stand/StandBlock.h"
#include "Move/injury/InjuryDuck.h"
#include "Move/injury/InjuryJump.h"
#include "Move/injury/InjuryStand.h"
#include "Move/Victory.h"
#include "Move/Defeat.h"
#include "Move/SpecialMove.h"

class Player;

/*
Class of the characer's state.
Class is responsible for connecting between the character and its move.
Updating the correct move and supply data and status on the character.
*/
class State
{
public:

	//c-tor - arguments: nameOfCharacter - to get the appropriate textures of the character
	State(charName nameOfCharacter);

	//default d-tor
	~State();

	//function is responsible to transfer the window to draw for current move
	void draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent);

	//returns the current move the character is in
	characterSingleton::Movement getCurrent() const;

	//sets the received argument as the new move of the character
	void setMove(characterSingleton::Movement newMove);

	//returns if the current move can be change
	bool changeable();

	//returns if the character stands - including all the moves of standing
	bool isStandMode() const;

	//returns if the character ducking - including all the moves of ducking
	bool isDuckMode() const;

	//returns if the character jumps to the left
	bool isJumpSideLeft() const;

	//returns if the character jumps to the right
	bool isJumpSideRight() const;

	//returns if the character is blocking (defending)
	bool isBlockMode() const;

	//returns if current move is in action mode
	bool executeAction();

	//sets the current move to being hit (injury) - decides the new move by 
	//the player's and opponent's current move
	void setInjury(Player &injured, Player &attacker);

	//summons action of current move
	void action(Player &player, Player &opponent);

	//returns the size of the current sprite the character is in it
	sf::Vector2f getPlayerRectangleSize();

	//returns the float rectangle by according to character's current texture
	sf::FloatRect getFloatRect(sf::Vector2f pos);

	bool isJumpMode() const;
private:

	//holds current move
	characterSingleton::Movement _currentMode = characterSingleton::stand;

	//ordered map - holds all the availabe moves. Key - enum of all the moves
	std::map <characterSingleton::Movement, std::unique_ptr<Move>> _movemap;

};

