#include "PlayerAgent.h"
#include <iostream>

PlayerAgent::PlayerAgent()
{
	_directionQueue = new KTools::List<int>(2);
}

PlayerAgent::~PlayerAgent()
{
	delete _directionQueue;
}

void PlayerAgent::KeyDown(int key)
{
	if (_directionQueue->Count() >= 2)
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

	_directionQueue->Add(newDirection);
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