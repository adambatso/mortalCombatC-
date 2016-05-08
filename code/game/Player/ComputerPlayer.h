#pragma once
#include "Player.h"
#include "../..//Difficult/DifficultyEasy.h"
#include "../..//Difficult/DifficultyMedium.h"
#include "../..//Difficult/DifficultyHard.h"

class ComputerPlayer :
	public Player
{
public:
	//c-tor - arguments: nameOfCharacter - in order to load the appropriate textures
	//gameNum - to know whitch difficulty to create
	ComputerPlayer(charName nameOfCharacter, Difficulty::Difficult gameNum);
	//default d-tor
	~ComputerPlayer();

	//function updates character's move by object's decision tree.
	//opponent - to update if neseccery
	void makeDecision(Player & opponent);

	//returns if character is standing and blocking
	bool isStandBlock();

	//returns if character is ducking and blocking
	bool isDuckBlock();
	//returns if character is blocking (ducking/standing)
	bool isGneralBlock();
private:
	//pointer to level of difficulty of the character
	std::unique_ptr<Difficulty> _difficulty;

	//clock to count of much time elapsed since blocked human player's move
	sf::Clock _clBlock;

	//if blocked first time
	bool _fisrtTimeBlock = false;

	//if ducked first time
	bool _fisrtTimeDuck = false;
};

