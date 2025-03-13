#pragma once
#include <iostream>
#include <chrono>
#include "SnakeTools/SnakeGraphics.h"
#include "SnakeTools/SnakeInput.h"
#include "StateMachine.h"
#include "PlayState.h"


class GameManager : public StateMachine
{
private:
	int _windowWidth;
	int _windowHeight;
	int _numCols;
	int _numRows;

	int _FPS = 60;
	double _frameTime;
	std::chrono::time_point<std::chrono::high_resolution_clock> _lastUpdateTime;
	int _timeDiff;

	SnakeGraphics* _gameWindow;

	Color _backgroundColour = Color(0, 0, 0);
	Color _wallColour = Color(15, 200, 15);
	Color _snakeColour = Color(200, 200, 10);
	Color _appleColour = Color(200, 10, 20);


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