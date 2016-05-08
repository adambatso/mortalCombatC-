#include "StatusBar.h"
#include <iostream>

//default c-tor
StatusBar::StatusBar()
{
	sf::Texture &text = GeneralSingleton::instance().getLifeBar();

	_player1.setSize(sf::Vector2f(text.getSize().x + 20, text.getSize().y + 10));
	_player2.setSize(sf::Vector2f(text.getSize().x + 20, text.getSize().y + 10));

	_player1.setTexture(&text);
	_player2.setTexture(&text);

	_timeText.setFont(GeneralSingleton::instance().getFont());
}

//default d-tor
StatusBar::~StatusBar()
{
}

//draws the life of each character and how much time left to the ened of the game
void StatusBar::draw(sf::RenderWindow &window, sf::View &view, const Player &pl1, const Player &pl2)
{
	//get the coordinates of each life box according to the view in the window
	sf::Vector2f firstRectPos(sf::Vector2f(view.getCenter().x - view.getSize().x / 2 + 5, view.getCenter().y - view.getSize().y / 2 + 5));
	sf::Vector2f secondRectPos(sf::Vector2f(view.getCenter().x + view.getSize().x / 2 - _player2.getSize().x - 5, view.getCenter().y - view.getSize().y / 2 + 5));

	//less life factor (the red rectangle)
	float redFctor = (100 - pl1.getLife())*_player1.getSize().x / 100;

	//set the position of the life rectagles according to the view in the window
	_player1.setPosition(firstRectPos);
	_player2.setPosition(secondRectPos);

	//draw life box
	window.draw(_player1);
	window.draw(_player2);

	//draw less life box
	sf::RectangleShape red(sf::Vector2f(redFctor, _player1.getSize().y - 4));
	red.setPosition(sf::Vector2f(_player1.getPosition().x, _player1.getPosition().y + 2));
	red.setFillColor(sf::Color::Red);
	window.draw(red);

	redFctor = (100 - pl2.getLife())*_player2.getSize().x / 100;
	red.setSize(sf::Vector2f(redFctor, _player1.getSize().y - 4));
	red.setPosition(sf::Vector2f(_player2.getPosition().x, _player2.getPosition().y + 2));
	red.setFillColor(sf::Color::Red);
	window.draw(red);


	//draw the time that is left to the end of the game
	_timeText.setString(std::to_string(LIMITSECONDTIME - int(_gameClock.getElapsedTime().asSeconds())));
	_timeText.setOrigin(sf::Vector2f(_timeText.getGlobalBounds().width / 2, _timeText.getGlobalBounds().height / 2));
	_timeText.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y - view.getSize().y / 2 + 5));
	window.draw(_timeText);
}

//returns if the game is ended and updtaes each character if he won or lost
bool StatusBar::endGame(Player &pl1, Player &pl2, size_t &humanVictory, size_t computerVictory) const
{
	//check if the time of the game has elapsed
	if (_gameClock.getElapsedTime().asSeconds() >= LIMITSECONDTIME)
	{
		//set the winner's and loser's moves 

		if (pl1.getLife() >= pl2.getLife())
		{
			pl1.setMove(characterSingleton::Defeat);
			pl1.setMove(characterSingleton::victory);
			humanVictory++;
		}
		else
		{
			pl2.setMove(characterSingleton::Defeat);
			pl2.setMove(characterSingleton::victory);
			computerVictory++;
		}

		return true;
	}

	//if pl1 won
	if (pl1.getLife() <= 0)
	{
		//set the winner's and loser's moves 
		pl1.setMove(characterSingleton::Defeat);
		pl2.setMove(characterSingleton::victory);
		computerVictory++;
		return true;
	}
	else if (pl2.getLife() <= 0)		//if pl2 won
	{
		//set the winner's and loser's moves 
		pl2.setMove(characterSingleton::Defeat);
		pl1.setMove(characterSingleton::victory);
		humanVictory++;
		return true;
	}

	//game didn't end
	return false;
}


void StatusBar::resetClock()
{
	_gameClock.restart();
}