#pragma once
#include "State.h"

class SnakeGraphics;

class EndState : public State
{
	EndState(SnakeGraphics* gameWindow);
	~EndState();

	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;

	void Update();
	void Render();
	void OnKeyDown(int key);
};