#include "World.h"
#include "Snake.h"

World::World()
	: _gameObjects(nullptr), _gameWindow(nullptr), _snakeBrain(nullptr)
{

}

World::World(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_gameObjects = new KTools::List<GameObject*>;

	_snakeBrain = new PlayerAgent();
	Snake* snake = new Snake(_gameWindow, 4, KTools::Vector3<int>(40, 30, 0), _snakeBrain);

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
}

void World::Update()
{
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

void World::DrawEnvironment()
{

}

void World::KeyDown(int key)
{
	_snakeBrain->KeyDown(key);
}

