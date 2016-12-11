#include <SDL.h>
#include <iostream>
#include "Game.h"
#include <thread>
#include <string>

using namespace std;


int main(int argc, char** argv)
{
	Game* game = new Game();

	//Adjust screen positions as needed
	game->Init( 300, 100, 800, 600);

	while (game->IsRunning())
	{
		game->Update();
		game->Render();
	}



	return 0;
}
