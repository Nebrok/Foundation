#include <typeinfo>
#include "../World.h"
#include "Snake.h"
#include "Wall.h"
#include "Apple.h"

Snake::Snake()
	: GameObject(), Brain(nullptr), _currentDirection(Direction::UP)
{

}

Snake::Snake(SnakeGraphics* gameWindow, World* world, int startingLength, KTools::Vector3<int> startingPosition, PlayerAgent* brain)
	: GameObject(gameWindow, world, startingPosition), Brain(brain)
{
	_body = KTools::List<KTools::Vector3<int>>((size_t)20);
	_currentDirection = Direction::UP;

	KTools::Vector3<int> bodyStarting(startingPosition.x, startingPosition.y + 1, 0);
	
	for (int i = 0; i < startingLength; i++)
	{
		_body.Add(bodyStarting);
	}
}

void Snake::Update()
{
	auto currentTime = std::chrono::high_resolution_clock::now();
	long long timeDiffMilliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - _lastUpdateTime).count();
	if (timeDiffMilliseconds < _moveTimeMilliseconds)
		return;
	
	CheckUpdateDirection();

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

void Snake::OnCollision(GameObject* otherObject)
{
	if (typeid(*otherObject) == typeid(Wall))
	{
		_world->GameOver();
	}
	if (typeid(*otherObject) == typeid(Snake))
	{
		if (otherObject == this)
		{
			CheckBodyCollision();
			return;
		}
		_world->GameOver();
	}
	if (typeid(*otherObject) == typeid(Apple))
	{
		Grow();
	}
}

KTools::List<KTools::Vector3<int>> Snake::GetPositions()
{
	KTools::List<KTools::Vector3<int>> positions(16);
	positions.Add(_position);
	for (int i = 0; i < _body.Count(); i++)
	{
		positions.Add(_body[i]);
	}

	return positions;
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

void Snake::CheckBodyCollision()
{
	for (int i = 0; i < _body.Count(); i++)
	{
		if (_position == _body[i])
			_world->GameOver();
	}
}

void Snake::Grow()
{
	KTools::Vector3<int> bodyEnd = _body[_body.Count() - 1];
	_body.Add(bodyEnd);
}
