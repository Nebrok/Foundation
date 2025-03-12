#include "Gamemanager.h"

GameManager::GameManager(int windowWidth, int windowHeight, int worldWidth, int worldHeight)
	: _windowWidth(windowWidth), _windowHeight(windowHeight), _numCols(worldWidth), _numRows(worldHeight)
{
	_gameWindow = new SnakeGraphics(_windowWidth, _windowHeight, _numCols, _numRows);
	Init();
}

GameManager::~GameManager()
{
	delete _gameWindow;
}

bool GameManager::Init()
{
	if (!_gameWindow->Init())
	{
		std::cout << "Failed to initialise graphics!\n";
		return false;
	}
	return true;
}

void GameManager::Run()
{
	while (_gameWindow->UpdateWindowMessages())
	{
		
		Update();
		Render();
		CleanUp();

		
	}
}

void GameManager::ClearMap()
{
	for (int i = 0; i < _numCols; i++)
	{
		_gameWindow->PlotTile(i, 0, 0, _wallColour, _wallColour, ' ');
		_gameWindow->PlotTile(i, _numRows - 1, 0, _wallColour, _wallColour, ' ');
	}

	for (int i = 0; i < _numRows; i++)
	{
		_gameWindow->PlotTile(0, i, 0, _wallColour, _wallColour, ' ');
		_gameWindow->PlotTile(_numCols -1, i, 0, _wallColour, _wallColour, ' ');
	}

	for (int i = 0; i < _numRows; i++)
	{
		for (int j = 0; j < _numCols; j++)
		{
			_gameWindow->PlotTile(0, i, 0, _backgroundColour, _backgroundColour, ' ');
		}
	}
}

void GameManager::Update()
{

}

void GameManager::Render()
{
	_gameWindow->Render();
}

void GameManager::CleanUp()
{
	ClearMap();
}