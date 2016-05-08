#pragma once


#include "../Button.h"

/*
	this class represent a button in menu and it inherit from button class.
	the class is abstract calss and each button that inherit from it 
	implament the action (the thing that it do when it pressed)
*/
class MenuButton
	:public Button
{
public:
	MenuButton(sf::Vector2f position, std::string title, bool isMarked = false);	//constructor that get postion of button title and if the button make 
	virtual ~MenuButton();

	virtual void action(sf::RenderWindow &window) = 0;								//get the window and active the action of the button 

};

