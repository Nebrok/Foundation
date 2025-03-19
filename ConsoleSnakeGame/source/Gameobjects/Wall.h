#pragma once
#include "GameObject.h"

class Wall : public GameObject
{
private:


public:
	Wall(SnakeGraphics* gameWindow, World* world);
	~Wall();

	void Update() override;
	void Render() override;
	void Destroy() override;
	bool PointCollides(KTools::Vector3<int> other) override;
	void OnCollision(GameObject* otherObject) override;
};