#pragma once
#include "SnakeTools/SnakeGraphics.h"
#include "State.h"


class PlayState: public State
{
private:
	SnakeGraphics* _gameWindow;

public:
	PlayState(SnakeGraphics* gameWindow);

	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;
};