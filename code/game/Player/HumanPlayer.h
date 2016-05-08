#pragma once
#include "Player.h"



/*
Class represents a human player (character) in the game.
The class is responsible for managing the player's life,state,
the position in the screen,drawing and to provide information
about the player if needed.
In addition, the class is responsible for updating the move of the character
by user's pressed keys.
*/
class HumanPlayer :
	public Player
{
public:

	//c-tor - arguments: nameOfCharacter - in order to load the appropriate textures
	HumanPlayer(charName nameOfCharacter);

	//default d-tor
	~HumanPlayer();

	//function updates character's move by user's pressed key.
	//arguments: keys - vector of last pressed keys, opponent - to update 
	//if neseccery
	void move(std::vector<sf::Keyboard::Key> &keys, Player &opponent);

	//returns if character is standing and blocking
	bool isStandBlock();

	//returns if character is ducking and blocking
	bool isDuckBlock();

	//returns if character is blocking (ducking/standing)
	bool isGneralBlock();

	//returns if user used special combination of keys to set special attack
	bool suitableCombination(std::vector<sf::Keyboard::Key> &keys, size_t currPos);
};

