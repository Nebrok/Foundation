#pragma once
#include "../SnakeTools/SnakeGraphics.h"
#include "Vector3.h"

class GameObject
{
protected:
	bool _isDestroyed;
	SnakeGraphics* _gameWindow;


public:
	GameObject(SnakeGraphics* gameWindow);
	virtual ~GameObject() { }

	bool virtual PointCollides(KTools::Vector3<int> otherPoint) = 0;

	void virtual Update() = 0;
	void virtual Render() = 0;
	void virtual Destroy() = 0;
	bool virtual IsDestroyed() { return _isDestroyed; }

};