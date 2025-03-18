#pragma once
#include "GameObject.h"
#include "Vector3.h"

class SnakeGrphics;

class Grid : public GameObject
{
	struct Tile
	{
		KTools::Vector3<int> Position;
		bool Occupied = false;

		Tile(int x = 0, int y = 0, bool occupied = false)
		{
			Position = KTools::Vector3<int>(x, y, 0);
			Occupied = occupied;
		}
	};

private:
	int _gridCols = 0;
	int _gridRows = 0;
	int _gridDataLength = 0;

	Tile* _gridData;


public:
	Grid(SnakeGraphics* gameWindow = nullptr, World* world = nullptr);
	~Grid();

	void LoadLevel(bool* levelData);
	void SetTileOccupancy(int x, int y, bool occupied);

	void Update() override;
	void Render() override;
	void Destroy() override;
	bool PointCollides(KTools::Vector3<int> other) override;


};