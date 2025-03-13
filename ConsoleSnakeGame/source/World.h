#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "List.h"
#include "GameObject.h"
#include "Snake.h"

class World
{
private:
	SnakeGraphics* _gameWindow;
	KTools::List<GameObject*>* _gameObjects;

public:
	World();
	World(SnakeGraphics* gameWindow);
	~World();

	void Update();
	void Render();

};