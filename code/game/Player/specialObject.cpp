#include "specialObject.h"

//c-tor - arguments: objects - textures while the object is moving
//collide - texture when the object collide opponent
specialObject::specialObject(std::vector <sf::Texture> &objects, std::vector <sf::Texture> &collide)
:_specialObject(objects), _collideObject(collide)
{

}

//d-tor
specialObject::~specialObject()
{
	
}

//set function - sets the needed information to start the object
//for moving
void specialObject::set(float posX, float posY, float offset)
{
	_position = sf::Vector2f(posX, posY);
	_offset = offset;
	_textureIndexSpecial = 0;
	_textureIndexCollide = 0;
	_collide = false;
}

//moves the object by the class member offset
void specialObject::moveObject()
{
	if (!_collide)
		_position.x+=_offset;
}

//return float rectangle of the object
sf::FloatRect specialObject::getFloatRect() const
{
	sf::RectangleShape rec(sf::Vector2f(_specialObject[_textureIndexSpecial].getSize()));
	rec.setOrigin(rec.getSize().x / 2, rec.getSize().y / 2);
	rec.setPosition(_position);

	return rec.getGlobalBounds();
}

//set _collide parameter to true
void specialObject::updateCollide()
{
	_collide = true;
}

//return true if the object left the screen
bool specialObject::outOfRange(sf::Vector2f oppPos) const
{

	if (_position.x > WINDOWX || _position.x < 0)
		return true;

	return false;
}

//return true if the object collided with opponent
bool specialObject::collide() const
{
	return _collide;
}

//return true if object reached to the last texture in _collideObject vector
bool specialObject::endOfAnimation() const
{
	if (_textureIndexCollide >= _collideObject.size() - 1)
		return true;

	return false;
}

//draws the object to the screen	
void specialObject::draw(sf::RenderWindow &window)
{
	sf::RectangleShape animationRec;

	_framecounter += _frameSpeed * _clock.restart().asSeconds();

	if (_collide)
	{
		animationRec.setSize(sf::Vector2f(_collideObject[_textureIndexCollide].getSize()));
		animationRec.setOrigin(animationRec.getSize().x / 2, animationRec.getSize().y / 2);
		animationRec.setPosition(_position);
		animationRec.setTexture(&(_collideObject[_textureIndexCollide]));

		//sets speed of frames
		if (_framecounter >= _switchFrame)
		{
			if (_textureIndexCollide<_collideObject.size()-1)
				_textureIndexCollide++;

			_framecounter = 0;				//reset frame counter

		}

	}
	else
	{
		
		animationRec.setSize(sf::Vector2f(_specialObject[_textureIndexSpecial].getSize()));
		animationRec.setOrigin(animationRec.getSize().x / 2, animationRec.getSize().y / 2);
		animationRec.setPosition(_position);
		animationRec.setTexture(&(_specialObject[_textureIndexSpecial]));

		//sets speed of frames
		if (_framecounter >= _switchFrame)
		{
			if (_textureIndexSpecial<_specialObject.size() - 1)
				_textureIndexSpecial++;

			_framecounter = 0;				//reset frame counter

		}
	}

	window.draw(animationRec);
}