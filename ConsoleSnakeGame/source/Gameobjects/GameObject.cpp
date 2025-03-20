#include "GameObject.h"
#include "Grid.h"
#include "../World.h"

GameObject::GameObject(SnakeGraphics* gameWindow, World* world, KTools::Vector3<int> startingPosition)
	: _gameWindow(gameWindow), _isDestroyed(false), _world(world)
{
	_position = startingPosition;
}

void GameObject::CheckCollision()
{
	Grid* worldGrid = _world->GetGrid();
	KTools::List<GameObject*>* gridOccupancy = worldGrid->GetTileOccupancy(_position.x, _position.y);
	int gridOccupancyCount = gridOccupancy->Count();
	for (int i = 0; i < gridOccupancyCount; i++)
	{
		if ((*gridOccupancy)[i] == this)
			continue;

		OnCollision((*gridOccupancy)[i]);
	}
}