#pragma once
#include <iostream>
#include "SnakeTools/SnakeGraphics.h"

class GameObject
{
protected:
	bool _isDestroyed;
	SnakeGraphics* _gameWindow;


public:
	GameObject(SnakeGraphics* gameWindow);
	virtual ~GameObject() { }

	void virtual Update() = 0;
	void virtual Render() = 0;
	void virtual Destroy() = 0;
	bool virtual IsDestroyed() { return _isDestroyed; }

};