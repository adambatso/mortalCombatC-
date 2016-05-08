#pragma once
#include "AttackMove.h"
#include "../Player/specialObject.h"
#include <vector>

class SpecialMove :
	public AttackMove
{
public:
	SpecialMove(std::vector <sf::Texture>& anime, std::vector <sf::Texture> &objects, std::vector <sf::Texture> &collide);
	~SpecialMove();

	void action(Player &player, Player &opponent);
	void draw(sf::RenderWindow &window, sf::Vector2f position, Player &opponent);
	bool checkBlock(Player &opponent);
	int getDamage(Player &player) const;
	int getDamageOpponentBlock(Player &player) const;
	void set(characterSingleton::Movement &oldMove);
	bool checkIfCollision(Player &player, Player &opponent);
	bool changeable() const;
	void nextFrame();

	void playSoundtype(){};

private:
	specialObject _object;

	bool _createObject = false;
	bool _changeable = false;
};

