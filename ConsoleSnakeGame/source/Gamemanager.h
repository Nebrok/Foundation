#pragma once
#include <iostream>
#include "SnakeTools/SnakeGraphics.h"
#include "StateMachine.h"
#include "PlayState.h"
#include "Snake.h"


class GameManager : public StateMachine
{
private:
	int _windowWidth;
	int _windowHeight;
	int _numCols;
	int _numRows;

	int _testMoveAmount = 20;
	int _moved = 0;

	int FPS = 60;
	SnakeGraphics* _gameWindow;

	Color _backgroundColour = Color(0, 0, 0);
	Color _wallColour = Color(15, 200, 15);
	Color _snakeColour = Color(200, 200, 10);
	Color _appleColour = Color(200, 10, 20);

	Snake _snake;

private:
	bool Init();
	void Update();
	void Render();
	void CleanUp();


	void ClearMap();

public:
	GameManager(int windowWidth, int windowHeight, int worldWidth, int worldHeight);
	~GameManager();

	void Run();

};