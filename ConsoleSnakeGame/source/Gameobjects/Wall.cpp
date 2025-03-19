#include "Wall.h"

Wall::Wall(SnakeGraphics* gameWindow = nullptr, World* world = nullptr)
	: GameObject(gameWindow, world)
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
}

void Wall::Destroy()
{
}

bool Wall::PointCollides(KTools::Vector3<int> other)
{
	return false;
}

void Wall::OnCollision(GameObject* otherObject)
{
}
