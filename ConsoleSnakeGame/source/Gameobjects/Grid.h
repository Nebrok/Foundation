#pragma once
#include "Vector3.h"
#include "List.h"

class SnakeGrphics;
class GameObject;

class Grid
{
	struct Tile
	{
		KTools::Vector3<int> Position;
		KTools::List<GameObject*>* OccupiedBy = nullptr;

		Tile(int x = 0, int y = 0)
		{
			Position = KTools::Vector3<int>(x, y, 0);
			OccupiedBy = new KTools::List<GameObject*>();
		}

		~Tile()
		{
			delete OccupiedBy;
		}

		void operator=(const Tile& other)
		{
			Position = other.Position;
			OccupiedBy = new KTools::List<GameObject*>(*other.OccupiedBy);
		}

	};

private:
	int _gridCols = 0;
	int _gridRows = 0;
	int _gridDataLength = 0;

	Tile* _gridData;


public:
	Grid(SnakeGraphics* gameWindow = nullptr);
	~Grid();

	void SetTileOccupancy(int x, int y, GameObject* occupier);

	void Update();
	bool PointCollides(KTools::Vector3<int> other);
	void OnCollision(GameObject* otherObject);


};