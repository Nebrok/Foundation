#pragma once
#include "GameObject.h"

class Apple : public GameObject
{
private:
	Color _appleColour = Color(235, 10, 10);

public:
	Apple(SnakeGraphics* gameWindow, World* world, KTools::Vector3<int> startingPosition);
	~Apple();

	void SetPosition(int x, int y);

	bool PointCollides(KTools::Vector3<int> otherPoint);
	void OnCollision(GameObject* otherObject);
	KTools::List<KTools::Vector3<int>> GetPositions();

	void Update();
	void Render();
	void Destroy();
};