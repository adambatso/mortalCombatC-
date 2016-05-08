#pragma once
#include <memory>
#include "Decision/Decision.h"

/*
	this class represent node of desition , it have unique_ptr to desition it need to 
	decide it holds node to ledt or right if it need (it mean if it not leaf) and every node 
	have id (the number of the node in the tree)
*/
class TreeNode
{
public:

	TreeNode(unsigned id, Decision *des);	//constructor that get id and pointer to desition 
	virtual ~TreeNode();					//default destructor it releases the smart pointers 

	Decision::NodeDesicion makeDecision(Player &player, Player &opponent);	//this function get player and opponent and decides what it the decition it need to do depend on the players
	TreeNode* getLeft() const;												//get the left node
	TreeNode* getRight() const;												//get the right node
	int getID() const;														//get the id of the current node
	void addLeft(TreeNode*newNode);											//add left node (it mean left son)
	void addRight(TreeNode*newNode);										//add right node

protected:
	unsigned _id;								//save the id of the node
	std::shared_ptr<TreeNode> _left, _right;	//save pointer to the right/left node (sons)
	std::unique_ptr<Decision> _decision;		//pointer to decision
};

