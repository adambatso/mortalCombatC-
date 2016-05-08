#pragma once
#include "CharacterSkill.h"

/*
Class represents the ability and power of Kitana character.
The class holds a range of powers for each type of attack,
it generates a number in the range and return the number.
The number is the power of the attack how summoned it.
*/
class CharacterSkillKitana :
	public CharacterSkill
{
public:
	//default c-tor
	CharacterSkillKitana();

	//default d-tor
	~CharacterSkillKitana();
};

