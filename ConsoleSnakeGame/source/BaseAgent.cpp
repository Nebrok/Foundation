#include <iostream>
#include "BaseAgent.h"

void BaseAgent::KeyDown(int key)
{
	std::cout << "BaseAgent calling KeyDown - Key pressed: " << key << "\n";
}