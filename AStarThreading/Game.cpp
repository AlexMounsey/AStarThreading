#include "Game.h"
#include <iostream>
#include <thread>


using namespace std;

Game::Game() :m_running(false)
{
}

Game::~Game()
{
}

bool Game::Init(int xpos, int ypos, int width, int height)
{
	srand(static_cast<unsigned int>(time(NULL)));

	Size2D winSize(800, 600);
	m_walls = 3;

	//tile width of view port
	float vpWidth = 20;

	//renderer init
	m_rend.init(winSize, "Astar Threading");


	float aspectRatio = winSize.w / winSize.h;
	Size2D vpSize(vpWidth, vpWidth / aspectRatio);
	Point2D vpBottomLeft(-vpSize.w / 2, -vpSize.h / 2);

	//set up the viewport
	Rect vpRect(vpBottomLeft, vpSize);
	m_rend.setViewPort(vpRect);

	m_running = true;

	float sizeX = vpSize.w / vpWidth;
	float sizeY = vpSize.h / vpWidth;



	for (int row = 0; row < vpWidth; row++)
	{
		for (int col = 0; col < vpWidth; col++)
		{
			// Setup Floor
			Tile temp;
			if (col >= 3 && col < vpWidth - 3 && row == (vpWidth / m_walls))
			{
				temp.Init((sizeX * row), (sizeY * col), sizeX, sizeY, tileType::WALL);
			}
			else
			{
				temp.Init((sizeX * row), (sizeY * col), sizeX, sizeY, tileType::TILE);
				if ((row + col) % 2 == 0)
				{
					temp.setColour(Colour(100, 100, 100));
				}
			}
			m_tileList.push_back(temp);
		}
	}
	return true;
}
void Game::Update()
{
}
void Game::Load()
{
}
void Game::Unload()
{
}
bool Game::IsRunning()
{
	return m_running;
}
void Game::Render()
{
	m_rend.clear(Colour(0, 0, 0));
	m_rend.present();
}


