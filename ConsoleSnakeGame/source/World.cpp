#include "World.h"
#include "Gameobjects/Snake.h"
#include "Gameobjects/Grid.h"
#include "Gameobjects/Wall.h"

World::World()
	: _gameObjects(nullptr), _gameWindow(nullptr), _snakeBrain(nullptr), _worldGrid(nullptr)
{

}

World::World(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();

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
	delete _gameObjects;
	delete _snakeBrain;
	delete _worldGrid;
}

void World::GameOver()
{
	_gameOver = true;
}

void World::Update()
{

	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->CheckCollision();
	}

	if (_gameOver)
	{
		std::cout << "Game Over!\n";
		return;
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
		KTools::Vector3<int> wall1StartingVec(i, 0, 0);
		Wall* wall1 = new Wall(_gameWindow, this, wall1StartingVec);
		_gameObjects->Add((GameObject*)wall1);
		worldGrid->SetTileOccupancy(wall1StartingVec.x, wall1StartingVec.y, wall1);

		KTools::Vector3<int> wall2StartingVec(i, _worldRows - 1, 0);
		Wall* wall2 = new Wall(_gameWindow, this, wall2StartingVec);
		_gameObjects->Add((GameObject*)wall2);
		worldGrid->SetTileOccupancy(wall2StartingVec.x, wall2StartingVec.y, wall2);
	}

	for (int i = 0; i < _worldRows; i++)
	{
		KTools::Vector3<int> wall1StartingVec(0, i, 0);
		Wall* wall1 = new Wall(_gameWindow, this, wall1StartingVec);
		_gameObjects->Add((GameObject*)wall1);
		worldGrid->SetTileOccupancy(wall1StartingVec.x, wall1StartingVec.y, wall1);

		KTools::Vector3<int> wall2StartingVec(_worldCols - 1, i, 0);
		Wall* wall2 = new Wall(_gameWindow, this, wall2StartingVec);
		_gameObjects->Add((GameObject*)wall2);
		worldGrid->SetTileOccupancy(wall2StartingVec.x, wall2StartingVec.y, wall2);
	}
}

