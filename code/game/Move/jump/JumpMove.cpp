#include "JumpMove.h"
#include "../../Player/Player.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites, offset - how many pixles the character 
//will move every draw, direction - the direction of the character (left/right)
JumpMove::JumpMove(std::vector <sf::Texture>& anime, float offset, characterSingleton::Movement direction)
:Move(anime), MovePosition(anime, offset, direction)
{
}

//default d-tor
JumpMove::~JumpMove()
{
}

//returns if the current status of the character's move is changeable
bool JumpMove::changeable() const
{
	return !_up;			//while going up  - not changeable
}

//set function - sets all the class members to default
void JumpMove::set(characterSingleton::Movement &oldMove)
{
	MovePosition::set(oldMove);

	_up = true;
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void JumpMove::action(Player &player, Player &opponent)
{
	float slope;				// Up/Down direction

	if (_actionMode)
	{
		if (player.getPosition().y <= JUMPLIMIT)
			_up = false;

		//if finished the jump
		if (player.getPosition().y >= GROUNDSTAND && !_up)
			_actionMode = false;
		

		//detemines if going up or down
		if (_up)
			slope = -0.5;
		else
			slope = 0.5;


		if (_offset<0)				//jump direction to the left
		{
			if (player.getPosition().x - player.getPlayerRectangleSize().x / 2>0)
				player.move(_offset, slope);
			else
				player.move(0, slope);
		}
		else if (_offset>0)			//jump direction to the right
		{
			if (player.getPosition().x + player.getPlayerRectangleSize().x / 2<WINDOWX)
				player.move(_offset, slope);
			else
				player.move(0, slope);
		}
			
		
	}
	
	//if finished the action mode
	if (!_actionMode)
		player.setMove(characterSingleton::stand);
	
}

//returns witch injury mode (stand/duck/jump) the character needs to be
void JumpMove::nextFrame()
{
	if (_animPos == _animationMove.size() - 1)
		_animPos = 1;
	else
		_animPos++;
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement JumpMove::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::jumpbeinghitLeft;
	else
		return characterSingleton::jumpbeinghitRight;

}