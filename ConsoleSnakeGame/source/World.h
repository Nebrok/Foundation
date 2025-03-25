#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "List.h"
#include "Gameobjects/GameObject.h"
#include "Agent/PlayerAgent.h"

class Grid;
class Wall;

class World
{
	int Score = 0;

private:
	SnakeGraphics* _gameWindow;
	KTools::List<GameObject*>* _gameObjects;
	Grid* _worldGrid;
	bool _gameOver = false;

	int currentLevel = 1;

	PlayerAgent* _snakeBrain;


	int _worldCols = 0;
	int _worldRows = 0;

	Color _wallColour = Color(15, 200, 15);

public:
	World();
	World(SnakeGraphics* gameWindow);
	~World();

	bool IsGameOver() { return _gameOver; }
	void GameOver();

	void Update();
	void Render();
	void KeyDown(int key);

	Grid* & GetGrid() { return _worldGrid; }
	void CreateLevel(Grid* worldGrid);
	bool* LoadLevelFromFile();

	void UpdateApple();

};