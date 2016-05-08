#include "BlockGenerator.h"


//consturctor that get block present 
BlockGenerator::BlockGenerator(unsigned blockProbability)
:_blockProbability(blockProbability), _distribution(1,100)
{
	unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();
	_generator.seed(seed);
}


BlockGenerator::~BlockGenerator()
{
}

//generate number and check if the player can block (it return true if the number is in the range  of block else false)
bool BlockGenerator::DrawBlock()
{

	int number = _distribution(_generator);

	if (0 < number && number <= _blockProbability)
		return true;

	return false;
}