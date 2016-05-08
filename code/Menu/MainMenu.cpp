#include "MainMenu.h"
#include "../singleton/ImageSingelton.h"

#include <iostream>

MainMenu::MainMenu()
{
}


MainMenu::~MainMenu()
{
}

//get pointer to button menu and add it to the vector
void MainMenu::addButton(MenuButton *buttonPtr)
{
	_buttons.emplace_back(buttonPtr);
}

//start the main menu by giving the window
void MainMenu::stratGame(sf::RenderWindow &window)
{
	sf::RectangleShape background(sf::Vector2f(800, 600));
	background.setTexture(&( ImageSingelton::instance().getBackground()));

	while (window.isOpen())
	{
		window.clear();
		
		//print background
		window.draw(background);

		//draw the buttons
		for each (gameButton button in _buttons)
			button->draw(window);

		window.display();

		sf::Event event;


		if (window.waitEvent(event))
		{
			switch (event.type)
			{
				//end the game 
			case sf::Event::Closed:
				window.close();
				return ;
				break;

				//check witch button is press and active his action 
			case sf::Event::EventType::KeyPressed:
				
				
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
				{
					for each (gameButton button in _buttons)
						if (button->isMarked())
						{
							button->delayTime();
							button->action(window);
						}
							

				}
				//change the mark button by the direction
				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
					setPressedButton(-1);

				else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
					setPressedButton(1);


			break;

			default:
				break;
			}
		}

	}
}

//get direction and set as mark  the currect button  
void MainMenu::setPressedButton(int dirOfChange)
{
	int currentPressed;

	for (size_t index = 0; index < _buttons.size(); index++)
	{
		if (_buttons[index]->isMarked())
		{
			_buttons[index]->setMark(false);
			currentPressed = index;
		}
	}

	currentPressed = (currentPressed + dirOfChange) % _buttons.size();


	_buttons[currentPressed]->setMark(true);
}