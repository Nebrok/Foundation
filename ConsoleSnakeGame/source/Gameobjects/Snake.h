#pragma once
#include <chrono>
#include "GameObject.h"
#include "Vector3.h"
#include "List.h"
#include "../Agent/PlayerAgent.h"

class Snake : public GameObject
{
public:
	enum class Direction
	{
		UP, LEFT, DOWN, RIGHT
	};
	
	PlayerAgent* Brain;

private:
	KTools::Vector3<int> _position;
	KTools::List<KTools::Vector3<int>> _body;

	Direction _currentDirection;

	int _moveTimeMilliseconds = 150;
	std::chrono::time_point<std::chrono::high_resolution_clock> _lastUpdateTime;

public:
	Snake();
	Snake(SnakeGraphics* gameWindow);
	Snake(SnakeGraphics* gameWindow, int startingLength, KTools::Vector3<int> startingPosition, PlayerAgent* brain);

	void Update();
	void Render();
	void Destroy();
	bool PointCollides(KTools::Vector3<int> otherPoint) override;

	void UpdateBody();
	void SetCurrentDirection(Direction);
	void CheckUpdateDirection();

};