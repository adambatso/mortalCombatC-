#include "Controller.h"
#include<iostream>

//c-tor - arguments: hPlayer - name of player the user chose
Controller::Controller(charName hPlayer)
: _humanPlayerCharacter(hPlayer), _arenaRec(sf::Vector2f(800, 600))
{

}

//default d-tor
Controller::~Controller()
{
}


//draws to window end of game message
void Controller::drawEndGameMsg(sf::RenderWindow &window, const sf::Text &txt)
{

	sf::Clock cl;
	while (cl.getElapsedTime().asSeconds() <= 2)
	{
		window.clear();
		window.draw(txt);
		window.display();
	}

}

//function of building new game to play, reponsible of updating the game view,
//generate an enemy and arena. In addition it stops the games when a player won
void Controller::controlGame(sf::RenderWindow &window)
{
	size_t gameNum = 0;								//holds current number of game
	size_t humanVictory = 0, computerVictory = 0;	//counts victories

	//set end of game messeage
	sf::Text gameFinishMassage;
	gameFinishMassage.setFont(GeneralSingleton::instance().getFont());
	gameFinishMassage.setOrigin(sf::Vector2f(gameFinishMassage.getGlobalBounds().width / 2, gameFinishMassage.getGlobalBounds().height / 2));
	gameFinishMassage.setPosition(sf::Vector2f(400, 300));

	//vectors of used character and arenas
	std::vector<characterSingleton::character> usedCharacters;
	std::vector<ImageSingelton::Arena> usedArenas;


	//engine for creating random numbers
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distributionCharacters(0,characterSingleton::instance().numOfCharacters()-1);
	std::uniform_int_distribution<int> distributionArenas(0, ImageSingelton::instance().getNumOfArenas() - 1);

	//number generator
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);
	

	while (gameNum<NUMOFGAMES)
	{
		//set view
		sf::View windowView(sf::FloatRect(100, 0, WINDOWX - VIEWFOCUESOFFSET, 600));
		window.setView(windowView);

		//create human player
		_player = std::make_unique<HumanPlayer>(_humanPlayerCharacter);

		//create computer player
		bool createComputerPlayer = false;
		while (!createComputerPlayer)
		{
			//generates new player that wasn't before
			int number = distributionCharacters(generator);

			//check if already generated player
			auto it = std::find(usedCharacters.begin(), usedCharacters.end(), number);

			//if generated a new player - set the player
			if (it == usedCharacters.end())
			{
				
				createComputerPlayer = true;
				usedCharacters.push_back(charName(number));
				_computer = std::make_unique<ComputerPlayer>(charName(number), Difficulty::Difficult(gameNum));
			}

		}

		//create game arena
		bool createArena = false;
		while (!createArena)
		{
			//generates new arena that wasn't before
			int number = distributionArenas(generator);

			//check if already generated arena
			auto it = std::find(usedArenas.begin(), usedArenas.end(), number);

			//if generated a new arena - set the arena
			if (it == usedArenas.end())
			{

				createArena = true;
				usedArenas.push_back(ImageSingelton::Arena(number));
				_arenaRec.setTexture(&ImageSingelton::instance().getArenaTexture(number));

			}
		}

		//play the game - return false if game ended suddenly
		if (!playGame(window, windowView, humanVictory, computerVictory, gameNum))
			break;

		//check victories
		if (humanVictory == 2)
		{
			gameFinishMassage.setString("You Win");
			drawEndGameMsg(window, gameFinishMassage);		
			return;
		}
			

		else if (computerVictory == 2)
		{
			gameFinishMassage.setString("You Lose");
			drawEndGameMsg(window, gameFinishMassage);
			return;
		}

		gameNum++;
	}
	
	sf::View originalView(sf::FloatRect(0, 0, 800, 600));
	window.setView(originalView);
}

//play game function. responsible of managing the game loop, updating the characters moves, draw the battle and 
//the needed information
bool Controller::playGame(sf::RenderWindow &window, sf::View &windowView, size_t &humanVictory, size_t computerVictory, int gameNum)
{

	//set limit of window to move in eacg side
	sf::Vector2f windowCenter(sf::Vector2f(window.getSize().x / 2, window.getSize().y / 2));
	int viewLimitLeft = windowCenter.x - VIEWFOCUESOFFSET/2;
	int viewLimitRight = windowCenter.x + VIEWFOCUESOFFSET/2;

	//set acdtion clock - how much time to wait until checking user's pressed keys
	sf::Clock actionTime;	
	float limit = 0.2;		//limit of how much time to wait until checking user's pressed keys

	//draws to window start of game message - round number and start
	startGame(window, windowView, gameNum);

	//set game clock to start - 00:00
	_statusBar.resetClock();

	std::vector<sf::Keyboard::Key> keys;	//user's pressed keys
	sf::Clock cl;							//wait time in the loop

	//game loop
	while (true)
	{
		//wait time
		cl.restart();
		while (cl.getElapsedTime().asSeconds() < 0.0009);

		//draw & set view
		window.clear();
		//draw & view
		window.draw(_arenaRec);
		_player->draw(window, *_computer);
		_computer->draw(window, *_player);

		//update players
		_player->action(*_computer);
		_computer->action(*_player);
		_statusBar.draw(window, windowView, *_player, *_computer);
		window.display();

		//check if game is ended
		if (_statusBar.endGame(*_player, *_computer, humanVictory, computerVictory))
		{
			GeneralSingleton::instance().playSound(GeneralSingleton::endmach);	//play end of game sound
			sf::Clock victoryClock;												//time to display the victory moves

			//if game is ended draw the players moves (victory/defeat)
			while (victoryClock.getElapsedTime().asSeconds() <= 2)
			{
				window.clear();
				window.draw(_arenaRec);
				_player->draw(window, *_computer);
				_computer->draw(window, *_player);
				_player->action(*_computer);
				_computer->action(*_player);
				_statusBar.draw(window, windowView, *_player, *_computer);
				window.display();
			
			}
			windowView.reset(sf::FloatRect(0, 0, 800, 600));
			window.setView(windowView);
			return true;
		}

		//set view center as center of players x ccordinate 
		sf::Vector2f fPlayer = _player->getPosition();
		sf::Vector2f sPlayer = _computer->getPosition();
		sf::Vector2f center((fPlayer.x + sPlayer.x) / 2, 300);
		
		//checking if didnt go out of view limits
		if (center.x>viewLimitLeft && center.x<viewLimitRight)
			windowView.setCenter(center);
		
		window.setView(windowView);

		//manage events
		sf::Event event;
		sf::Clock eventClock;
	
		//if no event continue
		window.pollEvent(event);

		switch (event.type)
		{
		//user closed window
		case sf::Event::Closed:
			window.close();
			return false;
			break;

		//user pressed escape key
		case sf::Event::EventType::KeyPressed:		
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Escape))
				return false;

			//check if its legal key
			if (inUsedKeys(event.key.code)) 
			{
				//updates only if user didnt pressed before
				auto it = std::find(keys.begin(), keys.end(), event.key.code);
				if (it == keys.end())
				{
					keys.push_back(event.key.code);
				}
					
			}
				
			break;
		default:
			break;
		}
		
		//checks if need to update human and compuer characters
		if (directionPressed() || actionTime.getElapsedTime().asSeconds() > limit)
		{
			//player choices
			_player->move(keys, *_computer);
			//computer choises
			if (actionTime.getElapsedTime().asSeconds() > limit)
			{
				_computer->makeDecision(*_player);
				actionTime.restart();
			}
				

			//erase last user keys
			keys.erase(keys.begin(), keys.end());
		}

	}

}

//function returns true if a direction key is pressed
bool Controller::directionPressed() const
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
		return true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		return true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		return true;
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
		return true;

	return false;
}

//function checks if received pressed key is a llegal key.If legal return true, else - false
bool Controller::inUsedKeys(sf::Keyboard::Key keyCode) const
{
	switch (keyCode)
	{

	case sf::Keyboard::A:			//higth kick
	case sf::Keyboard::E:			// block
	case sf::Keyboard::Q:			//higth punch
	case sf::Keyboard::S:			//low kick
	case sf::Keyboard::W:			//low punch
		return true;

		break;

	default:
		return false;
		break;
	}
}

//draws to window start of game message - round number and start
void Controller::startGame(sf::RenderWindow &window, sf::View &view, int gameNum)
{
	sf::Clock nextSound;
	sf::RectangleShape fightRec(sf::Vector2f(ImageSingelton::instance().getFightTexture().getSize()));
	fightRec.setTexture(&ImageSingelton::instance().getFightTexture());

	nextSound.restart();

	//time to play next sound
	while (nextSound.getElapsedTime().asSeconds() <= 0.9);

	//check witch number of game it is and plays appropriate sound
	gameNum++;
	switch (gameNum)
	{
	case 1:
		GeneralSingleton::instance().playSound(GeneralSingleton::roundone);
		break;
	case 2:
		GeneralSingleton::instance().playSound(GeneralSingleton::roundtwo);
		break;
	case 3:
		GeneralSingleton::instance().playSound(GeneralSingleton::roundthree);
		break;
	default:
		break;
	}

	//draw the message
	window.clear();
	window.draw(_arenaRec);
	_statusBar.draw(window, view, *_player, *_computer);

	fightRec.setOrigin(fightRec.getGlobalBounds().width / 2, fightRec.getGlobalBounds().height / 2);
	fightRec.setPosition(sf::Vector2f(view.getCenter().x, view.getCenter().y ));

	window.draw(fightRec);
	window.display();

	nextSound.restart();

	//wait untill finisehd playing sound
	while (nextSound.getElapsedTime().asSeconds() <= 2);

	GeneralSingleton::instance().playSound(GeneralSingleton::fight);



}