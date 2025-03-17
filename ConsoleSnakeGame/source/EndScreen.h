#pragma once

class SnakeGraphics;

class EndScreen
{
private:
	SnakeGraphics* _gameWindow;

	int _worldCols;
	int _worldRows;

public:
	EndScreen(SnakeGraphics* gameWindow = nullptr);
	~EndScreen();

	void Update();
	void Render();
	void OnKeyDown(int key);

private:
	void DrawWalls();
};