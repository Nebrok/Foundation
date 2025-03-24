#include "Apple.h"
#include "../World.h"
#include "Grid.h"
#include "Snake.h"

Apple::Apple(SnakeGraphics* gameWindow, World* world, KTools::Vector3<int> startingPosition)
	: GameObject(gameWindow, world, startingPosition)
{
	Grid* grid = _world->GetGrid();
	grid->SetTileOccupancy(_position.x, _position.y, this);
}

Apple::~Apple()
{
}

bool Apple::PointCollides(KTools::Vector3<int> otherPoint)
{
	if (otherPoint == _position)
		return true;
	return false;
}

void Apple::OnCollision(GameObject* otherObject)
{
	if (typeid(*otherObject) == typeid(Snake))
	{
		_world->UpdateApple();
	}
}

KTools::List<KTools::Vector3<int>> Apple::GetPositions()
{
	return KTools::List<KTools::Vector3<int>>();
}

void Apple::Update()
{
}

void Apple::Render()
{
	_gameWindow->PlotTile(_position.x, _position.y, 0, _appleColour, _appleColour, ' ');
}

void Apple::Destroy()
{
}

void Apple::SetPosition(int x, int y)
{
	Grid* grid = _world->GetGrid();

	grid->ClearTileOfGameobject(_position.x, _position.y, this);

	_position.x = x;
	_position.y = y;

	grid->SetTileOccupancy(_position.x, _position.y, this);
}
