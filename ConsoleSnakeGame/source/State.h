#pragma once
#include "List.h"

class State
{
public:
	const char* StateName;

private:
	KTools::List<State*>* _validTransitionStates;
	
	
public:
	State(const char* stateName);
	~State();

	void virtual EnterState() = 0;
	void virtual ExecuteState() = 0;
	void virtual ExitState() = 0;

	void AddValidTransitionState(State* newState);
	bool CheckValidTransitionState(State* newState);
};