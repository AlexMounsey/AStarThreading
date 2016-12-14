#include "Grid.h"


Grid::Grid()
{
}
void Grid::init(int numTiles, Size2D winSize, std::pair<int, int> start, std::pair<int, int> end)
{
	m_gridSize = numTiles;
	float sizeX = winSize.w / m_gridSize;
	float sizeY = winSize.h / m_gridSize;
	m_size = std::pair<int, int>(winSize.w / m_gridSize, winSize.h / m_gridSize);
	for (int row = 0; row < m_gridSize; row++)
	{
		for (int col = 0; col < m_gridSize; col++)
		{
			Tile temp(0,0);
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
		m_openNodes.push_back(m_tileList);
		}


	setStart(start);
	setEnd(end);
	setCurrent(start);

}
Grid::~Grid()
{
}

void Grid::Update()
{

	for (size_t i = 0; i < m_tileList.size(); i++)
	{
		if (checkList(m_closed, std::pair<int, int >(m_tileList[i].getPosition().first, m_tileList[i].getPosition().second)))
		{
			m_tileList[i].setType(tileType::PATH);
		}
	}
}
void Grid::render(Renderer* render)
{
	for (size_t i = 0; i < m_tileList.size(); i++)
	{
		m_tileList[i].render(render);
	}

	Tile temp(0, 0);
	temp.Init(m_start.first, m_start.second, m_size.first, m_size.second, tileType::START);
	temp.render(render);

	Tile temp2(0, 0);
	temp.Init(m_end.first, m_end.second, m_size.first, m_size.second, tileType::END);
	temp.render(render);
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

void Grid::checkNeighbours(std::pair<int, int> check)
{
	//xUp
	if (check.first - 1 >= 0 && isFree(std::pair<int, int>(check.first - 1, check.second)) && !isOpen(m_openNodes[check.first - 1][check.second])) //ensures it's not out of range or in the closed list or in the walls list
	{
			m_openNodes[check.first - 1][check.second] = Tile(check.first - 1, check.second);
			m_openNodes[check.first - 1][check.second].costOfTile(m_end, m_start);
			searchOrder.push(m_openNodes[check.first - 1][check.second]);
			setClose(check.first - 1, check.second);;
	}
	//Xdoen
	if (check.first + 1 < m_gridSize && isFree(std::pair<int, int>(check.first + 1, check.second)) && !isOpen(m_openNodes[check.first + 1][check.second]))
	{
			m_openNodes[check.first + 1][check.second] = Tile(check.first + 1, check.second);
			m_openNodes[check.first + 1][check.second].costOfTile(m_end, m_start);
			searchOrder.push(m_openNodes[check.first + 1][check.second]);
			setClose(check.first + 1, check.second);
	}
	//yLeft
	if (check.second - 1 >= 0 && isFree(std::pair<int, int>(check.first, check.second - 1)) && !isOpen(m_openNodes[check.first][check.second - 1]))
	{
			m_openNodes[check.first][check.second - 1] = Tile(check.first, check.second - 1);
			m_openNodes[check.first][check.second - 1].costOfTile(m_end, m_start);
			searchOrder.push(m_openNodes[check.first][check.second - 1]);
			setClose(check.first, check.second - 1);
	}
	//yRight
	if (check.second + 1 < m_gridSize && isFree(std::pair<int, int>(check.first, check.second + 1)) && !isOpen(m_openNodes[check.first][check.second + 1]))
	{
			m_openNodes[check.first][check.second + 1] = Tile(check.first, check.second + 1);
			m_openNodes[check.first][check.second + 1].costOfTile(m_end, m_start);
			searchOrder.push(m_openNodes[check.first][check.second + 1]);
			setClose(check.first, check.second + 1);
		
	}
}
bool Grid::isOpen(Tile tile)
{
		if (std::find(m_closed.begin(), m_closed.end(), std::pair<int, int> (tile.getPosition().first, tile.getPosition().second)) != m_closed.end())
		{
			return true;
		}
		else
		{
			return false;
		}
}
std::pair<int, int> Grid::getCurrent()
{
	return m_current;
}
void Grid::setCurrent(std::pair<int, int>curr)
{
	m_current = curr;
}
void Grid::setCurrent(int x, int y)
{
	m_current.first = x;
	m_current.second = y;
}
std::vector<std::pair<int, int>>  Grid::getClosed()
{
	return m_closed;
}
void Grid::setClose(std::pair<int, int> close)
{
	m_closed.push_back(close);
}
void Grid::setClose(int x, int y)
{
	m_closed.push_back(std::pair<int, int>(x,y));
}
std::pair<int, int> Grid::getStart()
{
	return m_start;
}
void Grid::setStart(std::pair<int, int> start)
{
	m_start = start;
}
void Grid::setStart(int x, int y)
{
	m_start.first = x;
	m_start.second = y;
}
std::pair<int, int> Grid::getEnd()
{
	return std::pair<int, int>();
}
void Grid::setEnd(std::pair<int, int>end)
{
	m_end = end;
}
void Grid::setEnd(int x, int y)
{
	m_end.first = x;
	m_end.second = y;
}
void Grid::RunaStar()
{

	checkNeighbours(m_current);


	m_previous = m_current; 
	Tile temp = searchOrder.top();
	searchOrder.pop(); 
	m_current = temp.getPosition();



}

