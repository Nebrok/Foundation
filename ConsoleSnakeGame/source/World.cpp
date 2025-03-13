#include "World.h"

World::World()
{

}

World::World(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_gameObjects = new KTools::List<GameObject*>;

	Snake* snake = new Snake(_gameWindow, 4, KTools::Vector3<int>(40, 30, 0));

	_gameObjects->Add(snake);

}

World::~World()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		delete (*_gameObjects)[i];
	}
	delete _gameObjects;
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
