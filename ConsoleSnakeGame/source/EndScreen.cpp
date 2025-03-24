#include "EndScreen.h"

EndScreen::EndScreen(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();

	const wchar_t* button1 = L"Main Menu";
	buttonText[0] = button1;

}

EndScreen::~EndScreen()
{

}

void EndScreen::Update()
{

}

void EndScreen::Render()
{
	DrawWalls();

	_gameWindow->PlotText(30, 15, 1, Color(0,0,0), L"Game Over!", Color(255, 255, 255), SnakeGraphics::Center);

	for (int i = 0; i < _numMenuItems; i++)
	{
		Color bg = Color(0, 0, 0);
		if (i == _currentHighlightedButton)
			bg = _highlightColour;

		_gameWindow->PlotText(30, 19 + i, 1, bg, buttonText[i], Color(255, 255, 255), SnakeGraphics::Center);
	}

	_gameWindow->Render();
}

void EndScreen::OnKeyDown(int key)
{
	switch (key)
	{
	case 38: //Up arrow
		if (_currentHighlightedButton > 0)
			_currentHighlightedButton--;
		break;
	case 40: //Down arrow
		if (_currentHighlightedButton < _numMenuItems - 1)
			_currentHighlightedButton++;
		break;
	case 13: //Enter
		Select();
	}
}

void EndScreen::Replay()
{
	_playAgain = true;
}

void EndScreen::Select()
{
	switch (_currentHighlightedButton)
	{
	case 0:
		Replay();
		break;
	}
}

void EndScreen::DrawWalls()
{
	Color wallColour = Color(15, 200, 15);

	for (int i = 0; i < _worldCols; i++)
	{
		_gameWindow->PlotTile(i, 0, 0, wallColour, wallColour, ' ');
		_gameWindow->PlotTile(i, _worldRows - 1, 0, wallColour, wallColour, ' ');
	}

	for (int i = 0; i < _worldRows; i++)
	{
		_gameWindow->PlotTile(0, i, 0, wallColour, wallColour, ' ');
		_gameWindow->PlotTile(_worldCols - 1, i, 0, wallColour, wallColour, ' ');
	}
}
