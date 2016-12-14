#define SDL_MAIN_HANDLED
#include <SDL.h>

#include <iostream>
#include "Game.h"
#include <thread>
#include <string>

using namespace std;


int main()
{
	Game* game = new Game();

	//Adjust screen positions as needed
	game->Init();

	while (game->IsRunning())
	{
		game->Update();
		game->Render();
	}



	return 0;
}
