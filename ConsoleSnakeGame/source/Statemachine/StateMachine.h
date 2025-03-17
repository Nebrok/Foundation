#pragma once
#include "List.h"

class State;

class StateMachine
{
protected:
	KTools::List<State*>* _possibleStates;
	State* _currentState;


public:
	StateMachine();
	~StateMachine();

	void BeginState(State* startingState);
	bool TransitionState(State* nextState);
	void Execute();

};