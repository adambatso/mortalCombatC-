#include "CharacterButton.h"

//constructor that get position ,character name of character and if it mark/unmark
CharacterButton::CharacterButton(sf::Vector2f position, characterSingleton::character charType,std::string nameChar, bool isMarked)
:Button(sf::Vector2f(TEXTX, TEXTY), nameChar, isMarked), _charType(charType)
{
	//set the size of the button and set the picture of it acoording the character that it get 
	_box.setSize(sf::Vector2f(WIDEX, WIDEY));
	_box.setPosition(position);
	_box.setTexture(&(characterSingleton::instance().getBox(charType)));
	_animation = characterSingleton::instance().getMovement(charType, characterSingleton::stand);
}


CharacterButton::~CharacterButton()
{
}

//draw the button and draw the animation of the character 
void CharacterButton::draw(sf::RenderWindow &window)
{
	sf::RectangleShape animationRec(sf::Vector2f(63, 129));
	animationRec.setPosition(sf::Vector2f(340, 250));


	if (_marked)
	{
		if (_firstMark)
		{
			_animPos = 0;
			_framecounter = 0;
			_firstMark = false;

		}
		//sets speed of frames
		_framecounter += _frameSpeed* _clock.restart().asSeconds();

		if (_framecounter >= _switchFrame)
		{
			_animPos++;
			//reset frame counter
			_framecounter = 0;

			if (_animPos == _animation.size())
				_animPos = 0;
			
		
		}

		animationRec.setTexture(&(_animation[_animPos]));
		
		window.draw(animationRec);
		
		_box.setOutlineThickness(2);
		_box.setOutlineColor(sf::Color::Green);
		window.draw(_title);
	}
	else
	{
		_firstMark = true;
		_box.setOutlineThickness(0);
	}
		

	window.draw(_box);
	

}

//return the type of the character that the button represent
characterSingleton::character  CharacterButton::getType() const
{
	return _charType;
}