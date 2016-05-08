#include "MenuButton.h"

//constructor that get postion of button title and if the button make 
MenuButton::MenuButton(sf::Vector2f position, std::string title, bool isMarked)
:Button(position,title,isMarked)
{
}


MenuButton::~MenuButton()
{
}

