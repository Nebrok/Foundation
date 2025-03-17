#pragma once
#include "BaseAgent.h"
#include "List.h"

class PlayerAgent : public BaseAgent
{
public: 
	int CurrentDirection = 0;

private:
	KTools::List<int>* _directionQueue;

public:
	PlayerAgent();
	~PlayerAgent();

	int GetNextDirection() override;
	void KeyDown(int key) override;
	bool PendingDirection();

	bool CheckInputValidity(int direction);
};