#include "PlayState.h"

PlayState::PlayState(SnakeGraphics* gameWindow)
	: State("PlayState"), _gameWindow(gameWindow), _endState(nullptr), _gameWorld(nullptr)
{
}

void PlayState::EnterState()
{
	SnakeInput::AddKeyDownCallback(std::bind(&PlayState::OnKeyDown, this, std::placeholders::_1));
	_gameWorld = new World(_gameWindow);
}

void PlayState::ExecuteState()
{
	Update();
	Render();
}

void PlayState::ExitState()
{
	ClearPendingTransition();
	SnakeInput::RemoveKeyDownCallback(std::bind(&PlayState::OnKeyDown, this, std::placeholders::_1));
	delete _gameWorld;
}

void PlayState::SetEndState(State* endState)
{
	_endState = endState;
	AddValidTransitionState(endState);
}

void PlayState::Update()
{
	_gameWorld->Update();
	if (_gameWorld->IsGameOver())
	{
		SetStateTransition(_endState);

	}

}

void PlayState::Render()
{
	_gameWorld->Render();
}

void PlayState::OnKeyDown(int key)
{
	_gameWorld->KeyDown(key);
}