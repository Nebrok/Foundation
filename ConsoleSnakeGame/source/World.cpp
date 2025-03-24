#include "World.h"
#include "Gameobjects/Snake.h"
#include "Gameobjects/Grid.h"
#include "Gameobjects/Wall.h"
#include "Gameobjects/Apple.h"

World::World()
	: _gameObjects(nullptr), _gameWindow(nullptr), _snakeBrain(nullptr), _worldGrid(nullptr)
{

}

World::World(SnakeGraphics* gameWindow)
	: _gameWindow(gameWindow)
{
	_worldCols = _gameWindow->GetNumColumns();
	_worldRows = _gameWindow->GetNumRows();

	_gameObjects = new KTools::List<GameObject*>;

	_worldGrid = new Grid(_gameWindow);
	CreateLevel(_worldGrid);

	int newX = (rand() % (_worldCols - 2)) + 1;
	int newY = (rand() % (_worldRows - 2)) + 1;
	Apple* apple = new Apple(_gameWindow, this, KTools::Vector3<int>(newX, newY, 0));

	_snakeBrain = new PlayerAgent();
	Snake* snake = new Snake(_gameWindow, this, 3, KTools::Vector3<int>(30, 20, 0), _snakeBrain);

	_gameObjects->Add((GameObject*)snake);
	_gameObjects->Add((GameObject*)apple);

}

World::~World()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		delete (*_gameObjects)[i];
	}
	delete _gameObjects;
	delete _snakeBrain;
	delete _worldGrid;
}

void World::GameOver()
{
	_gameOver = true;
}

void World::Update()
{

	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->CheckCollision();
	}

	//Clears the grid of snake occupancy
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		if (typeid(*(*_gameObjects)[i]) == typeid(Snake))
		{
			KTools::List<KTools::Vector3<int>> positions = (*_gameObjects)[i]->GetPositions();
			for (int j = 0; j < positions.Count(); j++)
			{
				_worldGrid->ClearTileOfGameobject(positions[j].x, positions[j].y, (*_gameObjects)[i]);
			}
		}
	}

	if (_gameOver)
	{
		std::cout << "Game Over!\n";
		return;
	}

	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->Update();
	}

	//Adds snake occupancy back to grid
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		if (typeid(*(*_gameObjects)[i]) == typeid(Snake))
		{
			KTools::List<KTools::Vector3<int>> positions = (*_gameObjects)[i]->GetPositions();
			for (int j = 0; j < positions.Count(); j++)
			{
				_worldGrid->SetTileOccupancy(positions[j].x, positions[j].y, (*_gameObjects)[i]);
			}
		}
	}
}

void World::Render()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		(*_gameObjects)[i]->Render();
	}

	wchar_t score[4];
	_itow_s(Score, score, 10);
	_gameWindow->PlotText(0, 0, 1, _wallColour, L"Score: ", Color(255, 255, 255), SnakeGraphics::Left);
	_gameWindow->PlotText(10, 0, 1, _wallColour, score, Color(255, 255, 255), SnakeGraphics::Left);

}

void World::KeyDown(int key)
{
	_snakeBrain->KeyDown(key);
}

void World::CreateLevel(Grid* worldGrid)
{
	for (int i = 0; i < _worldCols; i++)
	{
		KTools::Vector3<int> wall1StartingVec(i, 0, 0);
		Wall* wall1 = new Wall(_gameWindow, this, wall1StartingVec);
		_gameObjects->Add((GameObject*)wall1);
		worldGrid->SetTileOccupancy(wall1StartingVec.x, wall1StartingVec.y, wall1);

		KTools::Vector3<int> wall2StartingVec(i, _worldRows - 1, 0);
		Wall* wall2 = new Wall(_gameWindow, this, wall2StartingVec);
		_gameObjects->Add((GameObject*)wall2);
		worldGrid->SetTileOccupancy(wall2StartingVec.x, wall2StartingVec.y, wall2);
	}

	for (int i = 0; i < _worldRows; i++)
	{
		KTools::Vector3<int> wall1StartingVec(0, i, 0);
		Wall* wall1 = new Wall(_gameWindow, this, wall1StartingVec);
		_gameObjects->Add((GameObject*)wall1);
		worldGrid->SetTileOccupancy(wall1StartingVec.x, wall1StartingVec.y, wall1);

		KTools::Vector3<int> wall2StartingVec(_worldCols - 1, i, 0);
		Wall* wall2 = new Wall(_gameWindow, this, wall2StartingVec);
		_gameObjects->Add((GameObject*)wall2);
		worldGrid->SetTileOccupancy(wall2StartingVec.x, wall2StartingVec.y, wall2);
	}
}

void World::UpdateApple()
{
	for (int i = 0; i < _gameObjects->Count(); i++)
	{
		if (typeid(*(*_gameObjects)[i]) == typeid(Apple))
		{
			int newX = (rand() % (_worldCols - 2)) + 1;
			int newY = (rand() % (_worldRows - 2)) + 1;

			((Apple*)(*_gameObjects)[i])->SetPosition(newX, newY);
			Score++;
		}
	}
}

