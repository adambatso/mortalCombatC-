#pragma once

#include <SFML\Graphics.hpp>
#include <SFML\Audio.hpp>
#include <string>
#include "../singleton/GeneralSingleton.h"

/*
	this class represent a regular button , it have position and 
	text. it have function that every button need like if the 
	button set if it mark draw and etc.
	the draw function is virtual 
*/
class Button
{
public:
	Button(sf::Vector2f position, std::string title, bool isMarked = false);	//constructor that get the position of the button the title of the button and the button is marked
	virtual ~Button();	

	virtual void draw(sf::RenderWindow &window);								//draw the button
	bool isMarked() const;														//return true if the button is mark
	void setMark(bool set);														//get set and change the status of the button (mark/unmark)
	bool isPressed(sf::Vector2f pressVertex) const;								//get the position that press and return true if this is the postion of the button
	void delayTime() const;														//this function is to make smooth Switching between buttons  					

protected:
	bool _marked;		//save true of the button is mark
	sf::Text _title;	//save the title of the button 
};

