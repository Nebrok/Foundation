#include "Gamemanager.h"
#include "Statemachine/PlayState.h"
#include "Statemachine/MenuState.h"
#include "Statemachine/EndState.h"


GameManager::GameManager(int windowWidth, int windowHeight, int worldWidth, int worldHeight)
	: _windowWidth(windowWidth), _windowHeight(windowHeight), _numCols(worldWidth), _numRows(worldHeight)
{
	_frameTime = 1000000 / _FPS;
	_lastUpdateTime = std::chrono::high_resolution_clock::now();

	_gameWindow = new SnakeGraphics(_windowWidth, _windowHeight, _numCols, _numRows);
	Init();


	//Deletion is handled by the StateMachine destructor
	State* endState = new EndState(_gameWindow);
	_possibleStates->Add(endState);
	State* playState = new PlayState(_gameWindow, endState);
	_possibleStates->Add(playState);
	State* menuState = new MenuState(_gameWindow, playState);
	_possibleStates->Add(menuState);

	BeginState(menuState);
}

GameManager::~GameManager()
{
	_currentState->ExitState();

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
	if (!SnakeInput::Init(_gameWindow))
	{
		std::cout << "Input System failed init.\n";
		return false;
	}

	return true;
}

void GameManager::Run()
{
	while (_gameWindow->UpdateWindowMessages())
	{
		auto currentTime = std::chrono::high_resolution_clock::now();
		long long timeDiffMicroseconds = std::chrono::duration_cast<std::chrono::microseconds>(currentTime - _lastUpdateTime).count();
		if (timeDiffMicroseconds > _frameTime)
		{
			ClearWindow();
			Execute();

			//std::cout << "Time Diff in microseconds: " << timeDiffMicroseconds << "\n";
			_lastUpdateTime = std::chrono::high_resolution_clock::now();
		}
		
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

	_gameWindow->Render();
}

void GameManager::ClearWindow()
{
	for (int i = 0; i < _numCols; i++)
	{
		for (int j = 0; j < _numRows; j++)
		{
			_gameWindow->PlotTile(i, j, 0, _backgroundColour, _backgroundColour, ' ');
		}
	}
	_gameWindow->Render();
}

void GameManager::CleanUp()
{
	ClearMap();
}