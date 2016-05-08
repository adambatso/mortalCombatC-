#pragma once
#include "Difficulty.h"

/*
	this class represents easy level  of the computer difficulty  
	the class inherit from difficulty , and it build the map of decision and 
	execute. it give present for each decision.
	in easy mode the computer will attack lass and it will be lass aggressive.
	after it build the map the difficulty calss have the make decision function 
	that consider how to action by the present.
*/
class DifficultyEasy :
	public Difficulty
{
public:
	DifficultyEasy();			//default constructor call to build tree function
	~DifficultyEasy();			

	void buildTree();			//the functoin build the map of decision and execute. and it give present for each decision.
};

