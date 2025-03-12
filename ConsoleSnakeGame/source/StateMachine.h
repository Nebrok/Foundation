#pragma once
#include "List.h"
#include "State.h"


class StateMachine
{
protected:
	KTools::List<State*>* _possibleStates;
	State* _currentState;


public:
	StateMachine();
	~StateMachine();


	bool TransitionState(State* nextState);
	void Execute();

};