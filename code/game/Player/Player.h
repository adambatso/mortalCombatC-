#pragma once

#include  <SFML\Graphics.hpp>
#include "../State.h"
#include "CharacterSkill/CharacterSkill.h"
#include "CharacterSkill/CharacterSkillSubZero.h"
#include "CharacterSkill/CharacterSkillKitana.h"
#include "CharacterSkill/CharacterSkillLiuKang.h"
#include "CharacterSkill/CharacterSkillSonya.h"
#include <memory>

const float JUMPLIMIT = 250;
const float GROUNDSTAND = 450;
const float GROUNDDUCK = 475;
const float GROUNDEATH = 500;

/*
Class represents a player (character) in the game.
Abstract class.
The class is responsible for managing the player's life,state,
the position in the screen,drawing and to provide information
about the player if needed.
*/
class Player
{
public:

	//c-tor - arguments: pos - the player's position on the screen at the start of the game,
	//nameOfCharacter - in order to load the appropriate textures
	Player(sf::Vector2f pos, charName nameOfCharacter);

	//default d-tor
	virtual ~Player();

	//returns true if the player is in stand block move
	virtual bool isStandBlock() = 0;

	//returns true if the player is in duck block move
	virtual bool isDuckBlock() = 0;

	//returns true if the player is in block move
	virtual bool isGneralBlock() = 0;

	//function is responsible to transfer the window to draw for current move
	void draw(sf::RenderWindow &window, Player &opponent);
	//returns if the player can change is move
	bool changeable();

	//returns the position of the player on the screen
	sf::Vector2f getPosition() const;

	//checks if the player can use is current move and summons it if needed
	void action(Player &opponent);

	//moves the player in the screen by received argument (in pixles)
	void move(float pixOffsetX, float pixOffsetY);

	//moves the player down in order to duck in the screen by received argument (in pixles)
	void lowerPosition(float pixOffset);

	//returns the size of the current sprite the character is in it
	sf::Vector2f getPlayerRectangleSize();

	//returns the float rectangle by according to character's current texture
	sf::FloatRect getFloatRect();

	//set the injury mode (stand/duck/jump) the character needs to be, and decreases its
	//life by received parameter
	void setInjury(int parameter, Player &attacker);

	//returns the life of the player
	int getLife() const;

	//set new position of the player by received argument - newPos
	void setPosition(sf::Vector2f newPos);


	//returns if the player is ducking, including all the duck moves
	bool inDuckMode() const;

	//set new move of the player by received argument - newMove
	void setMove(characterSingleton::Movement newMove);

	//returns the current move the player is in
	characterSingleton::Movement getCurrentMode() const;


	//returns if the player is in a jump that can changed
	bool changeableJump() const;

	//returns true if the oppnent is left to player,else - the opponent is right to 
	//the player and return false
	bool opponentLeft(const Player &opponent) const;

	//decrease the life of the player by received argument
	void decreaseLife(int parameter);

	//return if character is jumping
	bool isJumpMode() const;

	//return power of kick attack
	int getKickPower() const;

	//return power of punch attack
	int getPunchPower() const;

	//return power of special attack
	int getSpecialPower() const;

protected:
	int _life = 100;									//current life of the player (0 - 100)
	sf::Vector2f _position;								//current position
	State _state;										//move management object of the player
	std::unique_ptr<CharacterSkill> _characterSkills;	//skill object
};

