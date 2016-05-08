#pragma once
#include "Difficulty.h"

/*
	this class represents medium level  of the computer difficulty
	the class inherit from difficulty , and it build the map of decision and
	execute. it give present for each decision.
	in medium mode the computer will attack and will  try to win (but still it will give 
	the player chance to win).
	after it build the map the difficulty calss have the make decision function
	that consider how to action by the present.
*/

class DifficultyMedium :
	public Difficulty
{
public:
	DifficultyMedium();			//default constructor call to build tree function
	~DifficultyMedium();

	void buildTree();			//the functoin build the map of decision and execute. and it give present for each decision.
};

