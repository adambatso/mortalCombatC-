#include "CharacterSkill.h"


//c -tor, arguments: punchRange - range of powers for punch attacks,
//kickRange - range of powers for kick attacks, splecialRange - range of powers for spcial attack
CharacterSkill::CharacterSkill(sf::Vector2i punchRange, sf::Vector2i kickRange, sf::Vector2i splecialRange)
:_punch(punchRange), _kick(kickRange), _special(splecialRange)
{
}

//default d-tor
CharacterSkill::~CharacterSkill()
{
}

//get power of kick attack
int CharacterSkill::getKickPower() const
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(_kick.x, _kick.y);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);

	return distribution(generator);
}

//get power of punch attack
int CharacterSkill::getPunchPower() const
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(_punch.x, _punch.y);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);

	return distribution(generator);
}

//get power of special attack
int CharacterSkill::getSpecialPower() const
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(_special.x, _special.y);

	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);

	return distribution(generator);
}