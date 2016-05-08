#include "Start.h"
#include <iostream>

//constructor that get the postion of the button and it also buidl the characters buttons 
Start::Start(sf::Vector2f position, bool isMarked)
:MenuButton(position, "Start Game", isMarked)
{
	//for each character it build button
	_charButton.emplace_back(new CharacterButton(sf::Vector2f(265, 150), characterSingleton::character::subZero, "Sub-Zero", true));
	_charButton.emplace_back(new CharacterButton(sf::Vector2f(340, 150), characterSingleton::character::sonya, "Sonya"));
	_charButton.emplace_back(new CharacterButton(sf::Vector2f(415, 150), characterSingleton::character::liuKang, "Liu-Kang"));
	_charButton.emplace_back(new CharacterButton(sf::Vector2f(490, 150), characterSingleton::character::kitana, "Kitana"));
}


Start::~Start()
{
}

//this function implement thae action of this button .when this button active it go to screen that the user will choose his character and then the game will start 
void Start::action(sf::RenderWindow &window)
{
	srand(time(nullptr));

	//screen setting
	sf::RectangleShape background(sf::Vector2f(800, 600));
	sf::Text header;


	header.setFont(GeneralSingleton::instance().getFont());
	header.setString("Select Your Fighter");
	header.setStyle(header.Bold);
	header.setOrigin(sf::Vector2f(header.getGlobalBounds().width / 2, header.getGlobalBounds().height / 2));
	header.setPosition(400, 50);

	background.setTexture(&(ImageSingelton::instance().getBackground()));

	charName selectedCharacter;
//========================================

	bool playerchhosed = false;	//savc true if the player select character
		
	GeneralSingleton::instance().playSound(GeneralSingleton::characterselect);

	//enter until the player chosse character
	while (!playerchhosed)
	{
		//draw section
		window.clear();

		window.draw(background);
		window.draw(header);

		for (int index = 0; index < _charButton.size(); index++)
			_charButton[index]->draw(window);
		
		window.display();
//===============================================

		sf::Event event;

		window.pollEvent(event);

		
		switch (event.type)
		{
		case sf::Event::KeyPressed:

			//check witch button the user select and get the type of the character 
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			{
				for (int index = 0; index < _charButton.size(); index++)
				{
					if (_charButton[index]->isMarked())
					{
						selectedCharacter = _charButton[index]->getType();
						GeneralSingleton::instance().playCharacterName(selectedCharacter);
						playerchhosed = true;
						break;
					}
						
					
				}
			}
				

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return;

			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			{
				sf::Clock cl;
				while (cl.getElapsedTime().asSeconds() < 0.2);
				setMarkedButton(1);
			}
				
			else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			{
				sf::Clock cl;
				while (cl.getElapsedTime().asSeconds() < 0.2);
				setMarkedButton(-1);
			}

			break;

		default:
			break;
		}

	}

	//give the character that the player choose and build the controller
	std::unique_ptr<Controller> controllerPtr(new Controller(selectedCharacter));

	//start the game
	controllerPtr->controlGame(window);
}


//this function set as mark the chracter button by  the direction it get	
void Start::setMarkedButton(int dirOfChange)
{
	int currentPressed;

	//set the current button that mark to unmark and the the new one to mark
	for (size_t index = 0; index < _charButton.size(); index++)
	{
		if (_charButton[index]->isMarked())
		{
			_charButton[index]->setMark(false);
			currentPressed = index;
		}
	}

	currentPressed = (currentPressed + dirOfChange) % _charButton.size();


	_charButton[currentPressed]->setMark(true);
}