#include "Execute.h"
#include "../../game/player/Player.h"

//get two paramenter that dedided what will be the range of the numbers that will generate randomly and will affact of the execute
Execute::Execute(int lowBound, int highBound )
:distribution(lowBound, highBound)
{
	//give seed to the generator
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	generator.seed(seed);
}

//default destructor
Execute::~Execute()
{
}

//the function get to player and decided what is the direction of the movement depend on the opponent
void Execute::setSideAtion(Player &player, Player &opponent, const characterSingleton::Movement left, const characterSingleton::Movement right) const
{

	//check what is the side of the opponent and set the move (depend on the side)
	if (player.opponentLeft(opponent))
		player.setMove(left);
	else
		player.setMove(right);
}
