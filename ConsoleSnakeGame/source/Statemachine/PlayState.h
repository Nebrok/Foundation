#pragma once
#include "../SnakeTools/SnakeGraphics.h"
#include "../SnakeTools/SnakeInput.h"
#include "State.h"
#include "../World.h"


class PlayState: public State
{
private:
	SnakeGraphics* _gameWindow;
	World* _gameWorld;
	State* _endState;

public:
	PlayState(SnakeGraphics* gameWindow, State* endState);

	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;
private:

	void Update();
	void Render();
	void OnKeyDown(int key);
};