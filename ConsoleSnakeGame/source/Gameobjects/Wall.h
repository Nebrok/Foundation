#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
public:
	Color WallColour = Color(15, 200, 15);

public:
	Wall(SnakeGraphics* gameWindow, World* world, KTools::Vector3<int> startingPosition);
	~Wall();

	void Update() override;
	void Render() override;
	void Destroy() override;

	bool PointCollides(KTools::Vector3<int> other) override;
	void OnCollision(GameObject* otherObject) override;
	KTools::List<KTools::Vector3<int>> GetPositions() override;

};