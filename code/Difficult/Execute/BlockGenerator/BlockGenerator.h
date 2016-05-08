#pragma once
#include <random>
#include <chrono>

/*
	this class represent and execture of block 
	it have one parameter that save the present of block to be set
	and it have functoin that draw the cahnge to set block 
	it return boolean .
*/
class BlockGenerator
{
public:
	BlockGenerator(unsigned blockProbability); //consturctor that get block present 
	~BlockGenerator();

	bool DrawBlock();							//generate number and check if the player can block (it return true if the number is in the range  of block else false)

private:
	//save the present to block
	unsigned _blockProbability;

	//save the generator to random numbers
	std::default_random_engine _generator;
	std::uniform_int_distribution<int> _distribution;
};

