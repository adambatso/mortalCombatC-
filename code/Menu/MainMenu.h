#pragma once

#include "MenuButtons/Credit.h"
#include "MenuButtons/Start.h"
#include <vector>
#include <memory>


/*
	this class responsible to imlement the menu of the game (when the user start the program)
	this class have vector of pointers to menue button (we use polimorpizem when we use the buttons)
	and have a function that add button to the menu so if in the future the game will have more button 
	it will be generic. 
*/
class MainMenu
{
public:
	MainMenu();
	~MainMenu();
	void addButton(MenuButton *buttonPtr);		//get pointer to button menu and add it to the vector
	void stratGame(sf::RenderWindow &window);	//start the main menu by giving the window

private:
	typedef std::shared_ptr<MenuButton> gameButton;

	std::vector <gameButton> _buttons;		//save smart pointers  vector  of menu button

	void setPressedButton(int dirOfChange);		//get direction and set as mark  the currect button  


};

