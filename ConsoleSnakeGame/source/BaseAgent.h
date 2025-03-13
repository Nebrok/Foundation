#pragma once


class BaseAgent
{
public:
	int virtual GetNextDirection() = 0;
	void virtual KeyDown(int key);
};