#pragma once
#include "SnakeTools/SnakeGraphics.h"


class SnakeGraphics;

class EndScreen
{
private:
	SnakeGraphics* _gameWindow;
	int _worldCols;
	int _worldRows;

	int _numMenuItems = 1;
	int _currentHighlightedButton = 0;

	const wchar_t* buttonText[1];

	bool _playAgain = false;

	Color _highlightColour = Color(10, 125, 10);

public:
	EndScreen(SnakeGraphics* gameWindow = nullptr);
	~EndScreen();

	void Update();
	void Render();
	void OnKeyDown(int key);

	void Select();
	void Replay();
	bool PlayAgain() { return _playAgain; }

private:
	void DrawWalls();
};