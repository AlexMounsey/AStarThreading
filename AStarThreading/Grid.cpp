#include "Grid.h"


Grid::Grid()
{
}
void Grid::init(int numTiles, Size2D winSize)
{
	m_gridSize = numTiles;
	float sizeX = winSize.w / numTiles;
	float sizeY = winSize.h / numTiles;
	for (int row = 0; row < numTiles; row++)
	{
		for (int col = 0; col < numTiles; col++)
		{
			Tile temp;
			temp.Init((sizeX * row), (sizeY * col), sizeX, sizeY, tileType::TILE);
				if ((row + col) % 2 == 0)
				{
					temp.setColour(Colour(0, 0, 0));
				}
				else
				{
					temp.setColour(Colour(255, 255, 255));
				}

				m_tileList.push_back(temp);
			}
		}
}
Grid::~Grid()
{
}

void Grid::Update()
{

}
void Grid::render(Renderer* render)
{
	for (size_t i = 0; i < m_tileList.size(); i++)
	{
		m_tileList[i].render(render);
	}
}


bool Grid::checkList(std::vector<std::pair<int, int>> list, std::pair<int, int> check)
{
	return std::find(list.begin(), list.end(), check) != list.end();
}
bool Grid::isFree(std::pair<int, int> check)
{
	if (checkList(m_closed, check))
	{
		return false;
	}
	else
	{
		return true;
	}
}

void Grid::checkNeighbours(std::pair<int, int> index)
{
	
}
void Grid::RunaStar()
{

}

