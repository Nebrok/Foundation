#include "MenuState.h"


MenuState::MenuState(SnakeGraphics* gameWindow)
	: State("MenuState"), _gameWindow(gameWindow)
{

}

void MenuState::EnterState()
{
	SnakeInput::AddKeyDownCallback(std::bind(&MenuState::OnKeyDown, this, std::placeholders::_1));
}

void MenuState::ExecuteState()
{
	Update();
	Render();
}

void MenuState::ExitState()
{
	SnakeInput::RemoveKeyDownCallback(std::bind(&MenuState::OnKeyDown, this, std::placeholders::_1));
}

void MenuState::Update()
{

}

void MenuState::Render()
{
}

void MenuState::OnKeyDown(int key)
{
}