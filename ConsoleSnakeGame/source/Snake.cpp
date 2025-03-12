#include "Snake.h"


Snake::Snake()
{
	_position = KTools::Vector3<int>(0);
	_body = KTools::List<KTools::Vector3<int>>();
	_currentDirection = Direction::UP;
}

Snake::Snake(int startingLength, KTools::Vector3<int> startingPosition)
{
	_position = startingPosition;
	_body = KTools::List<KTools::Vector3<int>>();
	_currentDirection = Direction::UP;

	for (int i = 0; i < startingLength; i++)
	{
		_body.Add(startingPosition);
	}
}

void Snake::Move()
{
	UpdateBody();
	switch (_currentDirection)
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

void Snake::UpdateBody()
{
	for (int i = _body.Count() - 1; i > 0; i--)
	{
		_body[i] = _body[i - 1];
	}
	_body[0] = _position;
}

void Snake::SetCurrentDirection(Direction newDirection)
{
	_currentDirection = newDirection;
}

void Snake::Render(SnakeGraphics* gameWindow, Color snakeColour)
{
	gameWindow->PlotTile(_position.x, _position.y, 0, snakeColour, snakeColour, ' ');
	for (int i = 0; i < _body.Count(); i++)
	{
		gameWindow->PlotTile(_body[i].x, _body[i].y, 0, snakeColour, snakeColour, ' ');

	}
}
