#include "Wall.h"

Wall::Wall(SnakeGraphics* gameWindow = nullptr, World* world = nullptr, KTools::Vector3<int> startingPosition = KTools::Vector3<int>(0,0,0))
	: GameObject(gameWindow, world, startingPosition)
{
}

Wall::~Wall()
{

}

void Wall::Update()
{
}

void Wall::Render()
{
	_gameWindow->PlotTile(_position.x, _position.y, 0, WallColour, WallColour, ' ');
}

void Wall::Destroy()
{
}

bool Wall::PointCollides(KTools::Vector3<int> other)
{
	if (other == _position)
		return true;
	return false;
}

void Wall::OnCollision(GameObject* otherObject)
{
}
