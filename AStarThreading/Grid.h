#pragma once
//Job To hold all the blocks and to find and add blocks to the level
#include "SDL.h"
#include "tile.h"
#include "BasicType.h"
#include <vector>
#include <queue>




class Grid
{
private:
	std::vector<Tile> m_tileList;
	int m_gridSize;
	//astar
	std::vector<std::vector<Tile>> m_openNodes;
	std::vector<std::pair<int, int>> m_closed;
	std::vector<std::pair<int, int>> m_walls;
	std::priority_queue<Tile> searchOrder;
	std::pair<int, int> m_start;
	std::pair<int, int> m_end;
	std::pair<int, int> m_current;
	std::pair<int, int> m_previous;

public:
	//grid stuff
	Grid();
	void init(int,Size2D);
	~Grid();
	void Update();
	void render(Renderer* render);


	//astar
	void RunaStar();
	bool checkList(std::vector<std::pair<int, int>> list, std::pair<int, int> check);
	bool isFree(std::pair<int, int> check);
	void checkNeighbours(std::pair<int, int> check);



};