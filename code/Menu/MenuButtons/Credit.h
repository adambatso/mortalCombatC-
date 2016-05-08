#pragma once
#include "MenuButton.h"



const float RETBUTTONX = 50;		//the x coordinate of the  postion of the return button 
const float RETBUTTONY = 500;		//the y coordinate of the  postion of the return button 

/*
	this class represent the credit of the game .
	it inherit from menu button and iplement the action function.
*/
class Credit :
	public MenuButton
{
public:
	Credit(sf::Vector2f position, bool isMarked = false);		//get the postion of the button and if it mark
	~Credit();
	void action(sf::RenderWindow &window);						//the function get the window and print the credit of the game 
};

