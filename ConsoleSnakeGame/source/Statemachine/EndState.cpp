#include "EndState.h"
#include "../SnakeTools/SnakeInput.h"
#include "../SnakeTools/SnakeGraphics.h"
#include "../EndScreen.h"

EndState::EndState(SnakeGraphics* gameWindow)
	: State("EndState"), _gameWindow(gameWindow), _menuState(nullptr)
{
}

EndState::~EndState()
{
}

void EndState::EnterState()
{
	SnakeInput::AddKeyDownCallback(std::bind(&EndState::OnKeyDown, this, std::placeholders::_1));
	_endScreen = new EndScreen(_gameWindow);
}

void EndState::ExecuteState()
{
	Update();
	Render();
}

void EndState::ExitState()
{
	ClearPendingTransition();
	SnakeInput::RemoveKeyDownCallback(std::bind(&EndState::OnKeyDown, this, std::placeholders::_1));
	delete _endScreen;
}

void EndState::Update()
{
	_endScreen->Update();
	if (_endScreen->PlayAgain())
	{
		SetStateTransition(_menuState);
	}
}

void EndState::Render()
{
	_endScreen->Render();
}

void EndState::OnKeyDown(int key)
{
	_endScreen->OnKeyDown(key);
}

void EndState::SetMenuState(State* menuState)
{
	_menuState = menuState;
	AddValidTransitionState(_menuState);
}
