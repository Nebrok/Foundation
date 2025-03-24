#include "MenuState.h"


MenuState::MenuState(SnakeGraphics* gameWindow)
	: State("MenuState"), _gameWindow(gameWindow), _mainMenu(nullptr), _playState(nullptr)
{

}

void MenuState::EnterState()
{
	SnakeInput::AddKeyDownCallback(std::bind(&MenuState::OnKeyDown, this, std::placeholders::_1));
	_mainMenu = new MainMenu(_gameWindow);

}

void MenuState::ExecuteState()
{
	Update();
	Render();
}

void MenuState::ExitState()
{
	ClearPendingTransition();
	SnakeInput::RemoveKeyDownCallback(std::bind(&MenuState::OnKeyDown, this, std::placeholders::_1));
	delete _mainMenu;
}

void MenuState::Update()
{
	_mainMenu->Update();
	if (_mainMenu->GameStart())
	{
		SetStateTransition(_playState);
	}
}

void MenuState::Render()
{
	_mainMenu->Render();
}

void MenuState::OnKeyDown(int key)
{
	_mainMenu->OnKeyDown(key);
}

void MenuState::SetPlayState(State* playState)
{
	_playState = playState;
	AddValidTransitionState(_playState);
}
