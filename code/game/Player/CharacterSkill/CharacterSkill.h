#pragma once

#include "../../../singleton/characterSingleton.h"
#include <chrono>
#include <random>

/*
Class represents the ability and power of the character.
The class holds a range of powers for each type of attack,
it generates a number in the range and return the number.
The number is the power of the attack how summoned it.
*/
class CharacterSkill
{
public:
	//c -tor, arguments: punchRange - range of powers for punch attacks,
	//kickRange - range of powers for kick attacks, splecialRange - range of powers for spcial attack
	CharacterSkill(sf::Vector2i punchRange, sf::Vector2i kickRange, sf::Vector2i splecialRange);

	//default d-tor
	virtual ~CharacterSkill();

	//get power of kick attack
	int getKickPower() const;

	//get power of punch attack
	int getPunchPower() const;

	//get power of special attack
	int getSpecialPower() const;

private:
	sf::Vector2i _punch;		//range of powers for punch attacks
	sf::Vector2i _kick;			//range of powers for kick attacks
	sf::Vector2i _special;		//range of powers for spcial attack
};

