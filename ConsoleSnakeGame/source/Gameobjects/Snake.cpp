#include "Snake.h"

Snake::Snake()
	: GameObject(nullptr), Brain(nullptr), _currentDirection(Direction::UP)
{

}

Snake::Snake(SnakeGraphics* gameWindow)
	: GameObject(gameWindow), Brain(nullptr), _currentDirection(Direction::UP)
{
	_position = KTools::Vector3<int>(0);
	_body = KTools::List<KTools::Vector3<int>>();
	_currentDirection = Direction::UP;
}

Snake::Snake(SnakeGraphics* gameWindow, World* world, int startingLength, KTools::Vector3<int> startingPosition, PlayerAgent* brain)
	: GameObject(gameWindow, world), Brain(brain)
{

	_position = startingPosition;
	_body = KTools::List<KTools::Vector3<int>>((size_t)20);
	_currentDirection = Direction::UP;

	for (int i = 0; i < startingLength; i++)
	{
		_body.Add(startingPosition);
	}
}

void Snake::Update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	long long timeDiffMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastUpdateTime).count();
	if (timeDiffMilliseconds < _moveTimeMilliseconds)
		return;
	
	CheckUpdateDirection();

	CheckForCollision();

	UpdateBody();
	UpdatePosition(_currentDirection);

	Brain->CurrentDirection = (int)_currentDirection;
	
	//Update internal clock
	_lastUpdateTime = std::chrono::high_resolution_clock::now();
}

void Snake::Render()
{
	Color snakeColour = Color(200, 200, 10);
	_gameWindow->PlotTile(_position.x, _position.y, 1, snakeColour, snakeColour, ' ');
	for (int i = 0; i < _body.Count(); i++)
	{
		_gameWindow->PlotTile(_body[i].x, _body[i].y, 1, snakeColour, snakeColour, ' ');

	}
}

void Snake::Destroy()
{

}

bool Snake::PointCollides(KTools::Vector3<int> otherPoint)
{
	if (otherPoint == _position)
		return true;
	for (int i = 0; i < _body.Count(); i++)
	{
		if (otherPoint == _body[i])
			return true;
	}
	return false;
}

void Snake::UpdateBody()
{
	for (int i = _body.Count() - 1; i > 0; i--)
	{
		_body[i] = _body[i - 1];
	}
	_body[0] = _position;
}

void Snake::UpdatePosition(Snake::Direction direction)
{
	switch (direction)
	{
	case Direction::UP:
		_position += KTools::Vector3<int>(0, -1, 0);
		break;

	case Direction::DOWN:
		_position += KTools::Vector3<int>(0, 1, 0);
		break;

	case Direction::LEFT:
		_position += KTools::Vector3<int>(-1, 0, 0);
		break;

	case Direction::RIGHT:
		_position += KTools::Vector3<int>(1, 0, 0);
		break;
	}
}

void Snake::SetCurrentDirection(Direction newDirection)
{
	_currentDirection = newDirection;
}

void Snake::CheckUpdateDirection()
{
	if (!Brain->PendingDirection())
		return;
	
	int direction = Brain->GetNextDirection();

	switch (direction)
	{
	case 0:
		_currentDirection = Snake::Direction::UP;
		break;
	case 1:
		_currentDirection = Snake::Direction::LEFT;
		break;
	case 2:
		_currentDirection = Snake::Direction::DOWN;
		break;
	case 3:
		_currentDirection = Snake::Direction::RIGHT;
		break;
	}
}

bool Snake::CheckForCollision()
{
	return false;
}


