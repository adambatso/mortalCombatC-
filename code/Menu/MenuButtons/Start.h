#pragma once
#include "MenuButton.h"
#include "../../singleton/GeneralSingleton.h"
#include "../CharacterButton.h"
#include "../../singleton/ImageSingelton.h"
#include "../../Controller.h"
#include <memory>

/*
	this class represent the start button and it inherit from menu button
	the calass implement the action function and when the 
	player choose this button it will go to a screen that he will choose 
	the character.this class take care of to sart the game after the player 
	choose his character.
*/
class Start :
	public MenuButton
{
public:
	Start(sf::Vector2f position, bool isMarked = false);			//constructor that get the postion of the button and it also buidl the characters buttons 
	~Start();

	
	void action(sf::RenderWindow &window);							//this function implement thae action of this button .when this button active it go to screen that the user will choose his character and then the game will start 
	void setMarkedButton(int dirOfChange);							//this function set as mark the chracter button by  the direction it get		
private:
	std::vector <std::unique_ptr<CharacterButton>> _charButton;		//save all the buttons of the characters 

};

