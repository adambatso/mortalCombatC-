#include "Button.h"

//constructor that get the position of the button the title of the button and the button is marked
Button::Button(sf::Vector2f position, std::string title, bool isMarked)
:_marked(isMarked)
{
	
	_title.setFont(GeneralSingleton::instance().getFont());
	_title.setPosition(position);
	_title.setString(title);

}


Button::~Button()
{
}

//draw the button
void Button::draw(sf::RenderWindow &window) 
{
	
	if (_marked)
		_title.setColor(sf::Color::Red);
	else 
		_title.setColor(sf::Color::White);

	window.draw(_title);
}

//return true if the button is mark
bool Button::isMarked() const
{
	return _marked;
}

//get set and change the status of the button (mark/unmark)
void Button::setMark(bool set)
{
	_marked = set;
}

//get the position that press and return true if this is the postion of the button
bool Button::isPressed(sf::Vector2f pressVertex) const
{
	return _title.getGlobalBounds().contains(pressVertex);
}

//this function is to make smooth Switching between buttons  
void Button::delayTime() const
{
	sf::Clock cl;
	while (cl.getElapsedTime().asSeconds() < 0.2);
}