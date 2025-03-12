#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "Vector3.h"
#include "List.h"

class Snake
{
	enum class Direction
	{
		UP, DOWN, LEFT, RIGHT
	};


private:
	KTools::Vector3<int> _position;
	KTools::List<KTools::Vector3<int>> _body;

	Direction _currentDirection;

public:
	Snake();
	Snake(int startingLength, KTools::Vector3<int> startingPosition);

	void Move();
	void UpdateBody();
	void SetCurrentDirection(Direction);

	void Render(SnakeGraphics* gameWindow, Color snakeColour);
};