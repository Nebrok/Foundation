#include "StateMachine.h"
#include "State.h"


StateMachine::StateMachine()
	: _currentState(nullptr)
{
	_possibleStates = new KTools::List<State*>(8);
}

StateMachine::~StateMachine()
{
	for (int i = 0; i < _possibleStates->Count(); i++)
	{
		delete (*_possibleStates)[i];
	}
	delete _possibleStates;
}

void StateMachine::BeginState(State* beginState)
{
	_currentState = beginState;
	_currentState->EnterState();
}

bool StateMachine::TransitionState(State* nextState)
{
	if (_currentState->CheckValidTransitionState(nextState))
	{
		_currentState->ExitState();
		_currentState = nextState;
		_currentState->EnterState();
	}
	else
	{
		return false;
	}
	return true;
}

void StateMachine::Execute()
{
	_currentState->ExecuteState();
	if (_currentState->CheckPendingStateTransition())
		TransitionState(_currentState->GetPendingTransitionState());

}