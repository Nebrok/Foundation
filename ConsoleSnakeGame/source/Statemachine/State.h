#pragma once
#include "List.h"

class StateMachine;

class State
{
public:
	const char* StateName;

private:
	KTools::List<State*>* _validTransitionStates;

	bool _pendingTransition = false;
	State* _pendingState = nullptr;
	
public:
	State(const char* stateName);
	~State();

	void virtual EnterState() = 0;
	void virtual ExecuteState() = 0;
	void virtual ExitState() = 0;

	void AddValidTransitionState(State* newState);
	bool CheckPendingStateTransition() { return _pendingState; }
	State* GetPendingTransitionState() { return _pendingState; }
	bool CheckValidTransitionState(State* newState);

protected:
	void SetStateTransition(State* newState);
	void ClearPendingTransition();

};