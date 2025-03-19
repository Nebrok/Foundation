#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "List.h"
#include "Gameobjects/GameObject.h"
#include "Agent/PlayerAgent.h"

class Grid;
class Wall;

class World
{
private:
	SnakeGraphics* _gameWindow;
	KTools::List<GameObject*>* _gameObjects;
	Grid* _worldGrid;

	PlayerAgent* _snakeBrain;
	Wall* _defaultWall;


	int _worldCols = 0;
	int _worldRows = 0;

	Color _wallColour = Color(15, 200, 15);

public:
	World();
	World(SnakeGraphics* gameWindow);
	~World();

	void Update();
	void Render();
	void KeyDown(int key);

	void CreateLevel(Grid* worldGrid);
};