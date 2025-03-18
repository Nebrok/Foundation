#include "GameObject.h"
#include "../World.h"

GameObject::GameObject(SnakeGraphics* gameWindow, World* world)
	: _gameWindow(gameWindow), _isDestroyed(false), _world(world)
{

}