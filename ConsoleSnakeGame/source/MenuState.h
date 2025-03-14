#pragma once
#include "State.h"
#include "SnakeTools/SnakeGraphics.h"
#include "SnakeTools/SnakeInput.h"

class MenuState : public State
{
private:
	SnakeGraphics* _gameWindow;

public:
	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;
private:
	MenuState(SnakeGraphics* gameWindow);

	void Update();
	void Render();
	void OnKeyDown(int key);
};