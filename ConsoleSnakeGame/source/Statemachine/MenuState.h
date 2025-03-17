#pragma once
#include "../SnakeTools/SnakeGraphics.h"
#include "../SnakeTools/SnakeInput.h"
#include "State.h"
#include "../MainMenu.h"

class MenuState : public State
{
private:
	SnakeGraphics* _gameWindow;

	MainMenu* _mainMenu;
	State* _playState;

public:
	MenuState(SnakeGraphics* gameWindow, State* playState);
	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;

	void Update();
	void Render();
	void OnKeyDown(int key);
};