#ifndef GAME_H
#define GAME_H
#include <SDL.h>
#include "Tile.h"
#include "Renderer.h"
#include <vector>
#include "Grid.h"

class Game
{
public:
	
	Game();
	~Game();

	void Unload();

	bool IsRunning();

	void Render();

	void Load();

	bool Init(int xpos, int ypos, int width, int height);

	void Update();

private:
	const int m_gridSize = 10;
	int m_walls;
	bool m_running;
	Renderer m_rend;
	Grid m_grid;
};
#endif