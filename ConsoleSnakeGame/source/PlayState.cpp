#include "PlayState.h"

PlayState::PlayState(SnakeGraphics* gameWindow) 
	: State("PlayState"), _gameWindow(gameWindow)
{
	_gameWorld = new World(_gameWindow);
	AddValidTransitionState(this);
}

void PlayState::EnterState()
{
	SnakeInput::AddKeyDownCallback(std::bind(&PlayState::OnKeyDown, this, std::placeholders::_1));

}

void PlayState::ExecuteState()
{
	Update();
	Render();
}

void PlayState::ExitState()
{
	SnakeInput::RemoveKeyDownCallback(std::bind(&PlayState::OnKeyDown, this, std::placeholders::_1));
	delete _gameWorld;
}

void PlayState::Update()
{
	_gameWorld->Update();
}

void PlayState::Render()
{
	_gameWorld->Render();
}

void PlayState::OnKeyDown(int key)
{
	_gameWorld->KeyDown(key);
}