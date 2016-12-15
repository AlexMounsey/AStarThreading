#pragma once
//Job To hold all the blocks and to find and add blocks to the level
#include "SDL.h"
#include "tile.h"
#include "BasicType.h"
#include <vector>
#include <queue>
#include <SDL_thread.h>




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
	std::pair<int, int> m_size;

public:
	//grid stuff
	Grid();
	void init(int numTiles, Size2D winSize, std::pair<int, int> start, std::pair<int, int> end);
	~Grid();
	void Update();
	void render(Renderer* render);


	//astar
	void RunaStar();
	bool checkList(std::vector<std::pair<int, int>> list, std::pair<int, int> check);
	bool isFree(std::pair<int, int> check);
	void checkNeighbours(std::pair<int, int> check);
	bool isOpen(Tile);


	std::pair<int, int> getCurrent();
	void setCurrent(std::pair<int, int>);
	void setCurrent(int, int);

	std::vector<std::pair<int, int>> getClosed();

	void setClose(std::pair<int, int> close);

	void setClose(int x, int y);

	std::pair<int, int> getStart();
	void setStart(std::pair<int, int>);
	void setStart(int, int);

	std::pair<int, int> getEnd();
	void setEnd(std::pair<int, int>);
	void setEnd(int, int);

};