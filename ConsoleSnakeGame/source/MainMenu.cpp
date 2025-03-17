#include "MainMenu.h"

MainMenu::MainMenu(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();

	const wchar_t* button1 = L"Play";
	const wchar_t* button2 = L"Credits";
	const wchar_t* button3 = L"Quit";

	buttonText[0] = button1;
	buttonText[1] = button2;
	buttonText[2] = button3;

}

MainMenu::~MainMenu()
{

}

void MainMenu::Update()
{

}

void MainMenu::Render()
{
	DrawWalls();

	for (int i = 0; i < _numMenuItems; i++)
	{
		Color bg = Color(0,0,0);
		if (i == _currentHighlightedButton)
			bg = _wallColour;

		_gameWindow->PlotText(30, 19 + i, 1, bg, buttonText[i], Color(255, 255, 255), SnakeGraphics::Left);
	}

	_gameWindow->Render();
}

void MainMenu::OnKeyDown(int key)
{
	switch (key)
	{
	case 38: //Up arrow
		if (_currentHighlightedButton > 0)
			_currentHighlightedButton--;
		break;
	case 40: //Down arrow
		if (_currentHighlightedButton < _numMenuItems-1)
			_currentHighlightedButton++;
		break;
	case 13: //Enter
		Select();
	}
}

void MainMenu::DrawWalls()
{
	for (int i = 0; i < _worldCols; i++)
	{
		_gameWindow->PlotTile(i, 0, 0, _wallColour, _wallColour, ' ');
		_gameWindow->PlotTile(i, _worldRows - 1, 0, _wallColour, _wallColour, ' ');
	}

	for (int i = 0; i < _worldRows; i++)
	{
		_gameWindow->PlotTile(0, i, 0, _wallColour, _wallColour, ' ');
		_gameWindow->PlotTile(_worldCols - 1, i, 0, _wallColour, _wallColour, ' ');
	}
}

void MainMenu::Play()
{
	_startGame = true;
}

void MainMenu::Select()
{
	switch (_currentHighlightedButton)
	{
	case 0:
		Play();
		break;
	}
}