#pragma once
#include <iostream>

class Player;

/*
	this class represent a decision between two thing,
	it is an abstract class and it hold left desicion 
	and right desition, it have virtual function that chack 
	witch decision it correct depend of the situation of the game.
	every class that inherit need to impament this function 
*/
class Decision
{
public:
	
	//save all the decision (right and left it for the tree nod)
	enum NodeDesicion {
		Left = 0, Right,
		JumpStand,
		JumpStandSpecial,
		GetcloserStand,
		GetcloserSpecial,
		JumpStandBackaway,
		GetcloserStandBackaway,
		StandBackawayDuckattack,
		Duckattack,
		Upperattack,
		Jumpattack,
		RandomattackStand,
		Donothing
	};

	Decision();																		//default constructor 
	Decision(NodeDesicion leftDes, NodeDesicion rightDes);							//constructor that get left and right decisions 
	virtual ~Decision();

	virtual NodeDesicion makeDecision(Player &player, Player &opponent) const=0;	//get the players and decided witch of the two decision is corect and return it 

protected:

	//save the left and right decision
	NodeDesicion _leftDesicion,
		_rightDesicion;
};

