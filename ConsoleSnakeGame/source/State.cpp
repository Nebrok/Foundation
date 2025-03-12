#include "State.h"

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

