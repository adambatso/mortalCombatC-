#pragma once
#include "../singleton/characterSingleton.h"
#include "TreeNode.h"
#include <map>
#include <memory>
#include "Execute/Execute.h"
#include "Decision/DistanceDecision.h"
#include "Decision/JumpDecision.h"
#include "Decision/OpponentBlockDecision.h"
#include "Decision/JumpDistanceDecision.h"
#include "Decision/OpponentDuckDecision.h"
#include "Decision/OpponentLifeDecision.h"
#include "Decision/OpponentStandDecision.h"
#include "Execute/JumpStand.h"
#include "Execute/Duckattack.h"
#include "Execute/GetcloserSpecial.h"
#include "Execute/GetcloserStand.h"
#include "Execute/GetcloserStandBackaway.h"
#include "Execute/Jumpattack.h"
#include "Execute/JumpStandBackaway.h"
#include "Execute/JumpStandSpecial.h"
#include "Execute/RandomAttack.h"
#include "Execute/StandBackawayDuckattack.h"
#include "Execute/UpperAttack.h"
#include "Execute/BlockGenerator/BlockGenerator.h"


/*
	this class represent the computer difficulty it mean this class responsible 
	to choose what is the next move of the computer this class hold 
	tree of decitions and map of execute , this class is abstract class 
	and all the difficulty inherit from it. 
*/
class Difficulty
{
public:
	enum Difficult {
		easy=0,medium,hard
	};

	Difficulty();					//difault constructor
	virtual ~Difficulty();			//difault destructor

	virtual void buildTree() = 0;
	void addRoot(TreeNode *node);										//add root to the tree decition
	void addNodeLeft(int existNodeID, int newNodeID, Decision *des);	//get id of nodes(new and old) and point to decition and add left node 
	void addNodeRight(int existNodeID, int newNodeID, Decision *des);	//get id of nodes(new and old) and point to decition and add right node 
	void makeDecision(Player &player, Player &opponent);				//this function get plyer and oppenent and make the decition for the computer player
	bool DrawBlock();													//this function draw block (if the opponent attack )


protected:
	std::shared_ptr<TreeNode> _rootStand;					//desicion tree when player stand
	DistanceDecision _playerJumpDecision;					//desicion  when player jump
	DistanceDecision _specialDecision;					//desicion  when opponent use special attack
	BlockGenerator _blockDesicion;
	std::map<Decision::NodeDesicion, std::unique_ptr <Execute>>  _excecuters;			//this map hold executre and node decition , for every decition it have unique execute

	bool searchNode(TreeNode *currentNode, TreeNode *&retPtr, int existNodeID) const;	
};

