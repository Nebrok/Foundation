#pragma once
#include "State.h"

class SnakeGraphics;

class EndState : public State
{
private:
	SnakeGraphics* _gameWindow;

public:
	EndState(SnakeGraphics* gameWindow);
	~EndState();

	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;

	void Update();
	void Render();
	void OnKeyDown(int key);
};