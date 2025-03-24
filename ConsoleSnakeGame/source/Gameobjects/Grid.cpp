#include "../SnakeTools/SnakeGraphics.h"
#include "Grid.h"

Grid::Grid(SnakeGraphics* gameWindow)
{
	_gridCols = gameWindow->GetNumColumns();
	_gridRows = gameWindow->GetNumRows();
	_gridDataLength = _gridCols * _gridRows;

	_gridData = new Tile[_gridDataLength];
	for (int i = 0; i < _gridDataLength; i++)
	{
		int x = i % _gridCols;
		int y = i / _gridCols;
		_gridData[i] = Tile(x, y);
	}

}

Grid::~Grid()
{
	delete[] _gridData;
}

void Grid::ClearTileOfGameobject(int x, int y, GameObject* occupier)
{
	KTools::List<GameObject*>* occupancy = GetTileOccupancy(x, y);
	for (int i = 0; i < occupancy->Count(); i++)
	{
		if (occupier == (*occupancy)[i])
		{
			occupancy->RemoveAt(i);
		}
	}
}

void Grid::SetTileOccupancy(int x, int y, GameObject* occupier)
{
	_gridData[y * _gridCols + x].OccupiedBy->Add(occupier);
}

KTools::List<GameObject*>* Grid::GetTileOccupancy(int x, int y)
{
	return _gridData[y * _gridCols + x].OccupiedBy;
}

void Grid::Update()
{
}

bool Grid::PointCollides(KTools::Vector3<int> other)
{
	for (int i = 0; i < _gridDataLength; i++)
	{
		if (_gridData[i].OccupiedBy->Count() == 0)
			continue;
		if (_gridData[i].Position == other)
			return true;
	}
	
	return false;
}
