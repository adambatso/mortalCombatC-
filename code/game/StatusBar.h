#pragma once

#include <SFML\Graphics.hpp>
#include "../singleton/GeneralSingleton.h"
#include "Player/Player.h"

const int LIMITSECONDTIME = 99;		//maximum time (in seconds) for a game


/*
Class responsible of managing the game's data,
drawing the needed data to the window and the sign when the
game is ended.
*/
class StatusBar
{
public:

	//default c-tor
	StatusBar();

	//default d-tor
	~StatusBar();

	//draws the life of each character and how much time left to the ened of the game
	void draw(sf::RenderWindow &window, sf::View &view, const Player &pl1, const Player &pl2);

	//returns if the game is ended and updtaes each character if he won or lost
	bool endGame(Player &pl1, Player &pl2, size_t &humanVictory, size_t computerVictory) const;

	void resetClock();
private:

	sf::RectangleShape _player1, _player2;		//life rectangle for each player
	sf::Clock _gameClock;						//current game's clock,counts time when the game starts
	sf::Text _timeText;							//text to print how much time is left
};

