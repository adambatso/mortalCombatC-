#include "Credit.h"

#include "../../singleton/ImageSingelton.h"


//get the postion of the button and if it mark
Credit::Credit(sf::Vector2f position, bool isMarked)
:MenuButton(position, "Credit", isMarked)
{
}


Credit::~Credit()
{
}

//the function get the window and print the credit of the game 
void Credit::action(sf::RenderWindow &window)
{
	//background of the screen
	sf::RectangleShape background(sf::Vector2f(800,600));
	sf::Text creditText;
	sf::Font font;
	

	font.loadFromFile("plus/mkx.ttf");
	creditText.setFont(font);

	//the credit of the game 
	creditText.setString("The game takes place on a fictional island in Earthrealm,where \n"
						"a tournament is being held at Shang Tsung's Island\n" 
						 "on which seven of its locations serve as stages in the game\n"
						 "The introduction to Mortal Kombat II explains that Shang Tsung\n"
						 "was banished to Earthrealm 500 years ago and,\n"
						 "with the help of the monstrous Goro, is able to seize control \n"
						 "of the Mortal Kombat tournament in an attempt to doom the realm.\n"
						 "For 500 years straight, Goro has never been defeated in the \n"
						 "tournament,and now a new generation of warriors must \n"
						 "challenge him.\n"
						 "\n\n By: Liron Amiel & Adam Ben Aharon ");

	//create button that return to the main menu
	Button retButton(sf::Vector2f(RETBUTTONX, RETBUTTONY), "Return", true);
	
	background.setTexture(&(ImageSingelton::instance().getBackground()));

	//print the screen until the user press return
	while (true)
	{
		window.clear();
	
		window.draw(background);
		window.draw(creditText);
		retButton.draw(window);
		window.display();

		sf::Event event;
		window.waitEvent(event);
		
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Return))
			return;
		
		if (event.MouseButtonPressed)
		{
			if (retButton.isPressed(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
				return;
		}
			
	}
}