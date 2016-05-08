#pragma once
#include "Button.h"
#include "../singleton/characterSingleton.h"

const float WIDEX = 48;		//save the wide of the character picture box 
const float WIDEY = 59;		//save the high of the character picture box 
const float TEXTX = 340;	//save the x coordinate of the button's postion
const float TEXTY = 370;	//save the Y coordinate of the button's postion

/*
	this class represent a character button in the start menue ,
	the class have the type of the character,and the animation of it.
	the character button have also function that return the type of the character
	that it represent. 
*/
class CharacterButton
	:public Button
{
public:
	CharacterButton(sf::Vector2f position, characterSingleton::character charType, std::string nameChar, bool isMarked = false);	//constructor that get position ,character name of character and if it mark/unmark
	~CharacterButton();

	void draw(sf::RenderWindow &window);								//draw the button and draw the animation of the character 

	characterSingleton::character  CharacterButton::getType() const;	//return the type of the character that the button represent


private:

	characterSingleton::character _charType;			//type of the character 
	sf::RectangleShape _box;							//the button with the picture of the character
	std::vector <sf::Texture> _animation;				//the animation of the character 
	size_t _animPos = 0;								//the postion in the _animation vector 
	bool _firstMark = true;								

	float _framecounter=0,
		_switchFrame=80, 
		_frameSpeed=1000;		//sprite tools to determine speed of frames 
	sf::Clock	_clock;		//counts time for switching frames
};

