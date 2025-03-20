#pragma once
#include "../SnakeTools/SnakeGraphics.h"
#include "Vector3.h"
#include "List.h"

class World;

class GameObject
{
protected:
	bool _isDestroyed;
	SnakeGraphics* _gameWindow;
	World* _world;

	KTools::Vector3<int> _position;



public:
	GameObject(SnakeGraphics* gameWindow = nullptr, World* world = nullptr, KTools::Vector3<int> startingPosition = KTools::Vector3<int>(0, 0, 0));
	virtual ~GameObject() { }

	void virtual CheckCollision();
	bool virtual PointCollides(KTools::Vector3<int> otherPoint) = 0;
	void virtual OnCollision(GameObject* otherObject) = 0;
	KTools::List<KTools::Vector3<int>> virtual GetPositions() = 0;

	void virtual Update() = 0;
	void virtual Render() = 0;
	void virtual Destroy() = 0;
	bool virtual IsDestroyed() { return _isDestroyed; }

};