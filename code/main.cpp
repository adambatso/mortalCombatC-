
#include <iostream>
#include "Menu/MainMenu.h"

int main()
{
	//create main menu
	MainMenu menu;

	//add main menu buttons
	menu.addButton(new Start(sf::Vector2f(100, 100), true));
	menu.addButton(new Credit(sf::Vector2f(100, 200)));

	sf::RenderWindow window;
	sf::VideoMode desktopMode = sf::VideoMode::getDesktopMode();
	window.create(sf::VideoMode(WINDOWX, WINDOWY), "ex1");

	//start the game
	menu.stratGame(window);


	return EXIT_SUCCESS;
}