#include "Defeat.h"
#include "../Player/Player.h"

//c-tor - arguments: anime - vector that holds the move sprites
Defeat::Defeat(std::vector <sf::Texture>& anime)
:Move(anime)
{
}

//default d-tor
Defeat::~Defeat()
{
}

//action function - executes the character's move and takes care of updating the character's & opponent's 
//current status
void Defeat::action(Player &player, Player &opponent)
{
	if (_actionMode)
	{
		if (player.getPosition().y <= GROUNDEATH)
			player.lowerPosition(1);
		else
			_actionMode = false;
	}

}