#include "Move.h"
#include "../Player/Player.h"
#include <iostream>

//c-tor - arguments: anime - vector that holds the move sprites
Move::Move(std::vector <sf::Texture>& anime)
:_animationMove(anime)
{
	_framecounter = 0;
	_switchFrame = 80;
	_frameSpeed = 1000;
}

//default d-tor
Move::~Move()
{
}

//draw function - draws the character to the window according to its position and its opponent position
//arguments: window - object to draw to, position - character's position, opponent - to get info on character's opponent
void Move::draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent)
{

	sf::RectangleShape animationRec(sf::Vector2f(_animationMove[_animPos].getSize()));

	animationRec.setOrigin(animationRec.getSize().x / 2, animationRec.getSize().y / 2);
	animationRec.setPosition(position);

	//sets speed of frames
	_framecounter += _frameSpeed* _clock.restart().asSeconds();
	
	if (_framecounter >= _switchFrame)
	{
		nextFrame();			

		_framecounter = 0;				//reset frame counter
		
	}

	animationRec.setTexture(&(_animationMove[_animPos]));
	
	//set charcter's texture side according to opponent
	if (opponent.getPosition().x < position.x)
		animationRec.setScale(-1, 1);
		

	window.draw(animationRec);

}

//set function - sets all the class members to default
void Move::set(characterSingleton::Movement &oldMove)
{
	_animPos = 0;
	_actionMode = true;
}

//returns if the current status of the character's move is changeable
bool Move::changeable() const
{
	return true;
}

//updates to appropriate image in the texture's vector
void Move::nextFrame()
{
	if (_animPos < _animationMove.size() - 1)
		_animPos++;
}

//returns if the character is in action mode
bool Move::getActionMode() const
{
	return _actionMode;
}

//returns the size of the current sprite the character is in it
sf::Vector2f Move::getPlayerRectangleSize() const
{
	return sf::Vector2f(_animationMove[_animPos].getSize());

}

//returns the float rectangle by according to character's current texture
sf::FloatRect Move::getFloatRect(sf::Vector2f pos) const
{
	sf::RectangleShape rec(sf::Vector2f(_animationMove[_animPos].getSize()));
	rec.setOrigin(rec.getSize().x / 2, rec.getSize().y / 2);
	rec.setPosition(pos);

	return rec.getGlobalBounds();
}

//returns witch injury mode (stand/duck/jump) the character needs to be
characterSingleton::Movement Move::getAppropriateInjuryMode(Player &injured, Player &attacker) const
{
	if (injured.getPosition().x < attacker.getPosition().x)
		return characterSingleton::standbeinghitLeft;
	else
		return characterSingleton::standbeinghitRight;
}