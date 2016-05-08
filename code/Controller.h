#pragma once

#include <memory>
#include "singleton/ImageSingelton.h"
#include "game/Player/HumanPlayer.h"
#include "game/Player/ComputerPlayer.h"
#include "game/StatusBar.h"

const int NUMOFGAMES = 3;	//mximum number of games

/*
Game Management Class.
The class is responsible for managing each game, to update when
one of the players (human or computer win) and return to the menu.
Each game the contoller is responsible of generating a new computer
opponent and a new arena.
In addition it manages the game loop and takes care of updating
both players move and draw the game to the screen.
*/
class Controller
{
public:
	//c-tor - arguments: hPlayer - name of player the user chose
	Controller(charName hPlayer);
	//default d-tor
	~Controller();

	//play game function. responsible of managing the game loop, updating the characters moves, draw the battle and 
	//the needed information
	bool playGame(sf::RenderWindow &window, sf::View &windowView, size_t &humanVictory, size_t computerVictory, int gameNum);

	//function of building new game to play, reponsible of updating the game view,
	//generate an enemy and arena. In addition it stops the games when a player won
	void controlGame(sf::RenderWindow &window);

	//function checks if received pressed key is a llegal key.If legal return true, else - false
	bool inUsedKeys(sf::Keyboard::Key keyCode) const;

	//function returns true if a direction key is pressed
	bool directionPressed() const;

private:
	std::unique_ptr<HumanPlayer> _player;		//human player
	std::unique_ptr<ComputerPlayer> _computer;	//computer player

	StatusBar _statusBar;						//the information in the game - life and time left
	sf::RectangleShape _arenaRec;				//arena rectangle to draw to window

	charName _humanPlayerCharacter;


	//draws to window end of game message
	void drawEndGameMsg(sf::RenderWindow &window, const sf::Text &txt);

	//draws to window start of game message - round number and start
	void startGame(sf::RenderWindow &window, sf::View &view, int gameNum);


};

