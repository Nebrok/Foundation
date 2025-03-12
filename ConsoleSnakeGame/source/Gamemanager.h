#pragma once
#include <iostream>
#include "SnakeTools/SnakeGraphics.h"


class GameManager
{
private:
	int _windowWidth;
	int _windowHeight;
	int _numCols;
	int _numRows;


	int FPS = 60;
	SnakeGraphics* _gameWindow;

	Color _backgroundColour = Color(0, 0, 0);
	Color _wallColour = Color(15, 200, 15);

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