#include "Difficulty.h"
#include "../game/Player/Player.h"


//this consturctor build the difficult it uild all the decition tree and the executre for the decitions
Difficulty::Difficulty()
:_playerJumpDecision(5, Decision::Jumpattack, Decision::Donothing), _specialDecision(250,Decision::JumpStand, Decision::Donothing), _blockDesicion(40)
{
	Decision *des = new DistanceDecision(200);
	addRoot(new TreeNode(1, des));
	des = new OpponentStandDecision();
	addNodeLeft(1, 2, des);
	des = new DistanceDecision(65, Decision::GetcloserStandBackaway, Decision::Left);
	addNodeRight(1, 3, des);

	des = new JumpDistanceDecision();
	addNodeLeft(2, 4, des);
	des = new JumpDecision(Decision::Left, Decision::GetcloserStand);
	addNodeRight(2, 5, des);

	des = new OpponentBlockDecision(Decision::StandBackawayDuckattack, Decision::Right);
	addNodeLeft(3, 6, des);

	des = new OpponentDuckDecision(Decision::Duckattack, Decision::Right);
	addNodeRight(6, 7, des);


	des = new JumpDecision(Decision::Upperattack, Decision::RandomattackStand);
	addNodeRight(7, 8, des);

	des = new OpponentLifeDecision(Decision::JumpStand, Decision::JumpStandSpecial);
	addNodeLeft(4, 9, des);
	des = new OpponentLifeDecision(Decision::GetcloserStand, Decision::GetcloserSpecial);
	addNodeRight(4, 10, des);

	des = new JumpDistanceDecision(Decision::JumpStandBackaway, Decision::JumpStand);
	addNodeLeft(5, 11, des);

}

//difault destructor
Difficulty::~Difficulty()
{
}

//add root to the tree decition
void Difficulty::addRoot(TreeNode *node)
{
	_rootStand.reset(node);

}

//get id of nodes(new and old) and point to decition and add left node
void Difficulty::addNodeLeft(int existNodeID, int newNodeID, Decision *des)
{
	//throw exception
	//if (!_root)
	TreeNode *tempRoot = _rootStand.get();
	TreeNode *temp = nullptr;
	
	if (searchNode(tempRoot, temp, existNodeID))
	{
		TreeNode *addNode = new TreeNode(newNodeID, des);
		temp->addLeft(addNode);
	}
		

	//throw exception
	//if (!temp)


}

//get id of nodes(new and old) and point to decition and add right node
void Difficulty::addNodeRight(int existNodeID, int newNodeID, Decision *des)
{
	TreeNode *tempRoot = _rootStand.get();
	TreeNode *temp = nullptr;

	if (searchNode(tempRoot, temp, existNodeID))
	{
		TreeNode *addNode = new TreeNode(newNodeID, des);
		temp->addRight(addNode);
	}
		
}

//this function get plyer and oppenent and make the decition for the computer player
void Difficulty::makeDecision(Player &player, Player &opponent)
{
	//jump & אם יש ירייה מיוחדת להתכופף אם לא עומד
	
	if (!player.changeable())
		return;

	if (player.changeableJump())
	{
		Decision::NodeDesicion des = _playerJumpDecision.makeDecision(player, opponent);
		if (des != Decision::Donothing)
			_excecuters[des]->execute(player, opponent);

		return;
		
	}
	//special attack reaction
	if (opponent.getCurrentMode() == characterSingleton::specialAttack)
	{
		Decision::NodeDesicion des = _specialDecision.makeDecision(player, opponent);
		if (des != Decision::Donothing)
			_excecuters[des]->execute(player, opponent);

	}
	
	if (!player.changeableJump())
	{

		//player.setMove(characterSingleton::stand);
		TreeNode *temp = _rootStand.get();

		//throw exceptions
		Decision::NodeDesicion des = temp->makeDecision(player, opponent);
		while (des == Decision::Left || des == Decision::Right)
		{
			if (des == Decision::Left)
				temp = temp->getLeft();
			else if (des == Decision::Right)
				temp = temp->getRight();

			des = temp->makeDecision(player, opponent);
		}

		_excecuters[des]->execute(player, opponent);
	}

}


bool Difficulty::searchNode(TreeNode *currentNode, TreeNode *&retPtr, int existNodeID) const
{
	if (!currentNode)
		return false;

	if (currentNode->getID() == existNodeID)
	{
		retPtr = currentNode;
		return true;
	}
		

	bool leftCheck = searchNode(currentNode->getLeft(), retPtr, existNodeID);
	if (leftCheck)
		return true;
	bool rightCheck = searchNode(currentNode->getRight(), retPtr, existNodeID);
	if (rightCheck)
		return true;

	return false;
}

//this function draw block (if the opponent attack )
bool Difficulty::DrawBlock()
{
	return _blockDesicion.DrawBlock();
}
