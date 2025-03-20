#include "EndState.h"
#include "../SnakeTools/SnakeGraphics.h"

EndState::EndState(SnakeGraphics* gameWindow)
	: State("EndState"), _gameWindow(gameWindow)
{
}

EndState::~EndState()
{

}

void EndState::EnterState()
{

}

void EndState::ExecuteState()
{
	Update();
	Render();
}

void EndState::ExitState()
{

}

void EndState::Update()
{
}

void EndState::Render()
{
	_gameWindow->PlotText(30, 20, 1, Color(0,0,0), L"Game Over!", Color(255, 255, 255), SnakeGraphics::Left);
}

void EndState::OnKeyDown(int key)
{
}

