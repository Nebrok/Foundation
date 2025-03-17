#include <iostream>
#include <string>
#include "Gamemanager.h"

#ifdef _DEBUG
#define new new (_NORMAL_BLOCK, __FILE__, __LINE__)
#endif

int main(int argc, const char* argv[])
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	GameManager* game = new GameManager(1024, 720, 60, 40);



	game->Run();


	delete game;
	return 0;
}