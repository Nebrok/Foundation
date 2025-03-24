#pragma once
#include "State.h"

class SnakeGraphics;
class EndScreen;

class EndState : public State
{
private:
	SnakeGraphics* _gameWindow;
	State* _menuState;
	EndScreen* _endScreen = nullptr;


public:
	EndState(SnakeGraphics* gameWindow);
	~EndState();

	void EnterState() override;
	void ExecuteState() override;
	void ExitState() override;

	void Update();
	void Render();
	void OnKeyDown(int key);

	void SetMenuState(State* menuState);

};