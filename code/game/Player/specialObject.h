#pragma once

#include "../../singleton/characterSingleton.h"
#include "../../singleton/GeneralSingleton.h"

/*
Special object attack class.
Class is repoinsiblr for moving the special object attack
and updating when there was an impact with the enemy.
*/
class specialObject
{
public:
	//c-tor - arguments: objects - textures while the object is moving
	//collide - texture when the object collide opponent
	specialObject(std::vector <sf::Texture> &objects, std::vector <sf::Texture> &collide);

	//d-tor
	~specialObject();
	
	//set function - sets the needed information to start the object
	//for moving
	void set(float posX, float posY, float offset);

	//moves the object by the class member offset
	void moveObject();

	//return float rectangle of the object
	sf::FloatRect getFloatRect() const;

	//return true if the object left the screen
	bool outOfRange(sf::Vector2f oppPos) const;

	//return true if the object collided with opponent
	bool collide() const;

	//return true if object reached to the last texture in _collideObject vector
	bool endOfAnimation() const;

	//draws the object to the screen
	void draw(sf::RenderWindow &window);

	//set _collide parameter to true
	void updateCollide();
private:

	//holds moving textures  
	std::vector <sf::Texture> &_specialObject;

	//holds collision textures
	std::vector <sf::Texture> &_collideObject;

	//holds position in window
	sf::Vector2f _position;

	//offset in pixles where to turn
	float _offset;

	//indexes for each vector
	size_t _textureIndexSpecial = 0, _textureIndexCollide = 0;

	//holds if collided the opponent
	bool _collide = false;

	//draw tools
	float _framecounter = 0,
		_switchFrame = 80,
		_frameSpeed = 1000;		//sprite tools to determine speed of frames 
	sf::Clock	_clock;		//counts time for switching frames
};

