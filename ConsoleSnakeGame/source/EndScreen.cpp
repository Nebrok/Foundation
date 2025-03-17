#include "EndScreen.h"
#include "SnakeTools/SnakeGraphics.h"

EndScreen::EndScreen(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();
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

	_gameWindow->PlotText(30, 20, 1, Color (0,0,0), L"Game Over", Color(255, 255, 255), SnakeGraphics::Center);


	_gameWindow->Render();
}

void EndScreen::OnKeyDown(int key)
{

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
