#include <iostream>
#include <string>
#include "Gamemanager.h"



int main(int argc, const char* argv[])
{
	GameManager* game = new GameManager(1024, 720, 80, 60);



	game->Run();

	return 0;
}