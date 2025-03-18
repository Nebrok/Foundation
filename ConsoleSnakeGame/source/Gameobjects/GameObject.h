#pragma once
#include "../SnakeTools/SnakeGraphics.h"
#include "Vector3.h"

class World;

class GameObject
{
protected:
	bool _isDestroyed;
	SnakeGraphics* _gameWindow;
	World* _world;


public:
	GameObject(SnakeGraphics* gameWindow = nullptr, World* world = nullptr);
	virtual ~GameObject() { }

	bool virtual PointCollides(KTools::Vector3<int> otherPoint) = 0;

	void virtual Update() = 0;
	void virtual Render() = 0;
	void virtual Destroy() = 0;
	bool virtual IsDestroyed() { return _isDestroyed; }

};