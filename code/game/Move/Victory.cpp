#include "Victory.h"
#include "../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
Victory::Victory(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
Victory::~Victory()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void Victory::action(Player &player, Player &opponent)
{
	if (_actionMode)
	{
		if (player.getPosition().y <= GROUNDSTAND)
			player.lowerPosition(1);
		else
			_actionMode = false;
	}
}