#include "TreeNode.h"

//constructor that get id and pointer to desition 
TreeNode::TreeNode(unsigned id, Decision *des)
:_id(id), _decision(des)
{

}

//default destructor it releases the smart pointers
TreeNode::~TreeNode()
{
}

//get the left node
TreeNode* TreeNode::getLeft() const
{
	return _left.get();
}

//get the right node
TreeNode * TreeNode::getRight() const
{
	return _right.get();
}

//get the id of the current node
int TreeNode::getID() const
{
	return _id;
}

//add left node (it mean left son)
void TreeNode::addLeft(TreeNode*newNode)
{
	_left.reset(newNode);
}

//add right node
void TreeNode::addRight(TreeNode*newNode)
{
	_right.reset(newNode);
}

//this function get player and opponent and decides what it the decition it need to do depend on the players
Decision::NodeDesicion TreeNode::makeDecision(Player &player, Player &opponent)
{
	//return the decition it make (it use polymorphism)
	return _decision->makeDecision(player,opponent);
}