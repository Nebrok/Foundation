#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "List.h"
#include "GameObject.h"
#include "PlayerAgent.h"

class World
{
private:
	SnakeGraphics* _gameWindow;
	KTools::List<GameObject*>* _gameObjects;
	PlayerAgent* _snakeBrain;

public:
	World();
	World(SnakeGraphics* gameWindow);
	~World();

	void Update();
	void Render();
	void KeyDown(int key);

};