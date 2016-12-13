#pragma once
//Job To hold all the blocks and to find and add blocks to the level
#include "SDL.h"
#include "tile.h"
#include "BasicType.h"
#include <vector>




class Grid
{
private:
	std::vector<Tile> m_tileList;

public:
	Grid();
	void init(int,Size2D);
	~Grid();

	void Update();
	void render(Renderer* render);
};