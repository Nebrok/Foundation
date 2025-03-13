#include "Gamemanager.h"

GameManager::GameManager(int windowWidth, int windowHeight, int worldWidth, int worldHeight)
	: _windowWidth(windowWidth), _windowHeight(windowHeight), _numCols(worldWidth), _numRows(worldHeight)
{
	_gameWindow = new SnakeGraphics(_windowWidth, _windowHeight, _numCols, _numRows);
	Init();
	if (!SnakeInput::Init(_gameWindow))
	{
		std::cout << "Input System failed init.\n";
	}

	//Deletion is handled by the StateMachine destructor
	State* playState = new PlayState(_gameWindow);
	_possibleStates->Add(playState);
	_currentState = playState;
	TransitionState(playState);
}

GameManager::~GameManager()
{
	SnakeInput::CleanUp();
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
		CleanUp();
		_currentState->ExecuteState();
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

	for (int i = 1; i < _numCols - 1; i++)
	{
		for (int j = 1; j < _numRows - 1; j++)
		{
			_gameWindow->PlotTile(i, j, 0, _backgroundColour, _backgroundColour, ' ');
		}
	}
	_gameWindow->Render();

}

void GameManager::Update()
{

}

void GameManager::Render()
{

}

void GameManager::CleanUp()
{
	ClearMap();
}