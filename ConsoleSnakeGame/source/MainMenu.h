#pragma once
#include "SnakeTools/SnakeGraphics.h"

class MainMenu
{
private:
	SnakeGraphics* _gameWindow;
	int _numMenuItems = 3;
	int _currentHighlightedButton = 0;

	const wchar_t* buttonText[3];


	int _worldCols;
	int _worldRows;


	Color _highlightColour = Color(10, 125, 10);
	Color _wallColour = Color(15, 200, 15);

	bool _startGame = false;


public:
	MainMenu(SnakeGraphics* gameWindow);
	~MainMenu();

	void Update();
	void Render();
	void OnKeyDown(int key);

	bool GameStart() { return _startGame; };

private:
	void DrawWalls();
	void Play();
	void Select();
};