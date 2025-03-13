#pragma once
#include "GameObject.h"
#include "Vector3.h"
#include "List.h"

class Snake : public GameObject
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
	Snake(SnakeGraphics* gameWindow);
	Snake(SnakeGraphics* gameWindow, int startingLength, KTools::Vector3<int> startingPosition);

	void Update();
	void Render();
	void Destroy();


	void UpdateBody();
	void SetCurrentDirection(Direction);

};