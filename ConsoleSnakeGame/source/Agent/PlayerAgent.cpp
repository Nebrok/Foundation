#include "PlayerAgent.h"
#include <iostream>

PlayerAgent::PlayerAgent()
{
	_directionQueue = new KTools::List<int>(32);
}

PlayerAgent::~PlayerAgent()
{
	delete _directionQueue;
}

void PlayerAgent::KeyDown(int key)
{
	if (_directionQueue->Count() >= 20)
	{
		return;
	}
	int newDirection = 0;
	switch (key)
	{
	case 87: // "w"
		newDirection = 0;
		break;
	case 65: // "A"
		newDirection = 1;
		break;
	case 83: // "S"
		newDirection = 2;
		break;
	case 68: // "D"
		newDirection = 3;
		break;
	}

	if (CheckInputValidity(newDirection))
	{
		_directionQueue->Add(newDirection);
		//std::cout << newDirection << "\n";
	}

}

bool PlayerAgent::CheckInputValidity(int direction)
{
	if ((CurrentDirection + direction) % 2 == 0) //sum of directions will be even if opposites
		return false;
	if (_directionQueue->Count() == 0) //if no inputs queued valid move
		return true;

	int lastDirection = (*_directionQueue)[_directionQueue->Count() - 1];
	if (lastDirection == direction)
		return false;
	if ((lastDirection + direction) % 2 == 0) //sum of directions will be even if opposites
		return false;
	return true;
}

int PlayerAgent::GetNextDirection()
{
	int direction = (*_directionQueue)[0];
	_directionQueue->RemoveAt(0);
	return direction;
}

bool PlayerAgent::PendingDirection()
{
	if (_directionQueue->Count() != 0)
	{
		return true;
	}
	return false;
}