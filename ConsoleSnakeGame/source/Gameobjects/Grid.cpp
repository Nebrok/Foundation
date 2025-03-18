#include "../SnakeTools/SnakeGraphics.h"
#include "Grid.h"

Grid::Grid(SnakeGraphics* gameWindow, World* world)
	: GameObject(gameWindow, world)
{
	_gridCols = gameWindow->GetNumColumns();
	_gridRows = gameWindow->GetNumRows();
	_gridDataLength = _gridCols * _gridRows;

	_gridData = new Tile[_gridDataLength];
	for (int i = 0; i < _gridDataLength; i++)
	{
		int x = i % _gridCols;
		int y = i / _gridCols;
		_gridData[i] = Tile(x, y, false);;
	}

}

Grid::~Grid()
{
	delete[] _gridData;
}

void Grid::LoadLevel(bool* levelData)
{
	for (int i = 0; i < _gridDataLength; i++)
	{
		if (levelData[i])
			_gridData[i].Occupied = true;
	}
}

void Grid::SetTileOccupancy(int x, int y, bool occupied)
{
	_gridData[y * _gridCols + x].Occupied = occupied;
}

void Grid::Update()
{
}

void Grid::Render()
{
	Color wallColour = Color(15, 200, 15);
	for (int i = 0; i < _gridDataLength; i++)
	{
		if (!_gridData[i].Occupied)
			continue;
		int xCoord = _gridData[i].Position.x;
		int yCoord = _gridData[i].Position.y;
		_gameWindow->PlotTile(xCoord, yCoord, 0, wallColour, wallColour, ' ');
	}
}

void Grid::Destroy()
{
}

bool Grid::PointCollides(KTools::Vector3<int> other)
{
	return false;
}
