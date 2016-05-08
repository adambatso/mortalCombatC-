#pragma once
#include "../MovePosition.h"

/*
Character move class - injury move.
Abstract class.
Responsible for drawing the appropriate sprites,update location of
character if needed and activate the move's action.
class applies the action for injury mode when hit adn the next frame.
*/
class InjuryMove :
	public MovePosition
{
public:

	//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
	//will move every draw, direction - the direction of the character (left/right)
	InjuryMove(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction);

	//default d-tor
	virtual ~InjuryMove();

	//action function - executes the character's move and takes care of updating the character's & opponent's 
	//current status
	virtual void action(Player &player, Player &opponent) = 0;

	//returns if the current status of the character's move is changeable
	virtual bool changeable() const;

	//updates to appropriate image in the texture's vector
	void nextFrame();

};

