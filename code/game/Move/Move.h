#pragma once


#include <vector>
#include <SFML\Graphics.hpp>
#include "../../singleton/characterSingleton.h"
#include "../../singleton/GeneralSingleton.h"

class Player;

/*
Character move class.
Abstract class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action
*/
class Move
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites
	Move(std::vector <sf::Texture>& anime);

	//default d-tor
	virtual ~Move();

	//draw function - draws the character to the window according to its position and its opponent position
	//arguments: window - object to draw to, position - character's position, opponent - to get info on character's opponent
	virtual void draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent);

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	virtual void action(Player &player, Player &opponent) =0;

	//set function - sets all the class members to default
	virtual void set(characterSingleton::Movement &oldMove);

	//returns if the current status of the character's move is changeable
	virtual bool changeable() const;

	//updates to appropriate image in the texture's vector
	virtual void nextFrame();

	//returns witch injury mode (stand/duck/jump) the character needs to be
	virtual characterSingleton::Movement getAppropriateInjuryMode(Player &injured, Player &attacker) const;

	//returns if the character is in action mode
	bool getActionMode() const;
	
	//returns the size of the current sprite the character is in it
	sf::Vector2f getPlayerRectangleSize() const;

	//returns the float rectangle by according to character's current texture
	sf::FloatRect getFloatRect(sf::Vector2f pos) const;
protected:
	
	//move's texture vector
	std::vector <sf::Texture> &_animationMove;

	//current image in the texture vector
	size_t _animPos = 0;

	//if move is in action mode
	bool _actionMode = true;

	//tools for srawing the sprites to window
	float _framecounter = 0,
		_switchFrame = 80,
		_frameSpeed = 1000;		//sprite tools to determine speed of frames 
	sf::Clock	_clock;		//counts time for switching frames

};

