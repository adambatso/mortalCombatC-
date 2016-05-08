#include "Decision.h"


//default constructor 
Decision::Decision()
:_leftDesicion(Left), _rightDesicion(Right)
{
}

//constructor that get left and right decisions 
Decision::Decision(NodeDesicion leftDes, NodeDesicion rightDes)
:_leftDesicion(leftDes), _rightDesicion(rightDes)
{
}


Decision::~Decision()
{
}
