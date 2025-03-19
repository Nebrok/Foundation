#include "World.h"
#include "Gameobjects/Snake.h"
#include "Gameobjects/Grid.h"
#include "Gameobjects/Wall.h"

World::World()
	: _gameObjects(nullptr), _gameWindow(nullptr), _snakeBrain(nullptr), _defaultWall(nullptr)
{

}

World::World(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();
	_defaultWall = new Wall(_gameWindow, this);

	_gameObjects = new KTools::List<GameObject*>;

	_worldGrid = new Grid(_gameWindow);
	CreateLevel(_worldGrid);



	_snakeBrain = new PlayerAgent();
	Snake* snake = new Snake(_gameWindow, this, 4, KTools::Vector3<int>(30, 20, 0), _snakeBrain);

	_gameObjects->Add((GameObject*)snake);

}

World::~World()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		delete (*_gameObjects)[i];
	}
	delete _defaultWall;
	delete _gameObjects;
	delete _snakeBrain;
}

void World::Update()
{

	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		for (int j = 0; j < _gameObjects->Count(); j++)
		{
			if (j == i)
				continue;
			(*_gameObjects)[i]->OnCollision((*_gameObjects)[j]);
		}
	}

	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->Update();
	}
}

void World::Render()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->Render();
	}
}

void World::KeyDown(int key)
{
	_snakeBrain->KeyDown(key);
}

void World::CreateLevel(Grid* worldGrid)
{
	for (int i = 0; i < _worldCols; i++)
	{
		worldGrid->SetTileOccupancy(i, 0, _defaultWall);
		worldGrid->SetTileOccupancy(i, _worldRows - 1, _defaultWall);
	}

	for (int i = 0; i < _worldRows; i++)
	{
		worldGrid->SetTileOccupancy(0, i, _defaultWall);
		worldGrid->SetTileOccupancy(_worldCols - 1, i, _defaultWall);
	}
}

