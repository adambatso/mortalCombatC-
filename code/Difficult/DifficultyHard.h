#pragma once
#include "Difficulty.h"

/*
this class represents hard level  of the computer difficulty
the class inherit from difficulty , and it build the map of decision and
execute. it give present for each decision.
in hard mode the computer will attack and will  try to win without mercy.
after it build the map the difficulty calss have the make decision function
that consider how to action by the present.
*/
class DifficultyHard :
	public Difficulty
{
public:
	DifficultyHard();		//default constructor call to build tree function
	~DifficultyHard();

	void buildTree();		//the functoin build the map of decision and execute. and it give present for each decision.
};

