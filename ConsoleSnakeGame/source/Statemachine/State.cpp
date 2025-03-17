#include "State.h"
#include "StateMachine.h"

State::State(const char* stateName)
	: StateName(stateName)
{
	_validTransitionStates = new KTools::List<State*>(8);
}

State::~State()
{
	delete _validTransitionStates;
}

void State::AddValidTransitionState(State* newState)
{
	_validTransitionStates->Add(newState);
}

bool State::CheckValidTransitionState(State* newState)
{
	for (int i = 0; i < _validTransitionStates->Count(); i++)
	{
		if ((*_validTransitionStates)[i]->StateName == newState->StateName)
		{
			return true;
		}
	}
	return false;
}

void State::SetStateTransition(State* newState)
{
	_pendingTransition = true;
	_pendingState = newState;
}

void State::ClearPendingTransition()
{
	_pendingState = nullptr;
	_pendingTransition = false;
}

