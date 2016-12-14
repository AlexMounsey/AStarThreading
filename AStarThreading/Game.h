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

	bool Init();

	void Update();

private:
	int m_walls;
	bool m_running;
	Renderer m_rend;
	Grid m_grid;
	std::pair<int, int> m_start;
	std::pair<int, int> m_end;
};
#endif