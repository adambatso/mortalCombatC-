#pragma once
#include "CharacterSkill.h"

/*
Class represents the ability and power of Sonya character.
The class holds a range of powers for each type of attack,
it generates a number in the range and return the number.
The number is the power of the attack how summoned it.
*/
class CharacterSkillSonya :
	public CharacterSkill
{
public:

	//default c-tor
	CharacterSkillSonya();

	//default d-tor
	~CharacterSkillSonya();
};

