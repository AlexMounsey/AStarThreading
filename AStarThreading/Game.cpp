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

bool Game::Init()
{
	srand(static_cast<unsigned int>(time(NULL)));

	Size2D winSize(600, 600);
	m_walls = 3;

	


	//tile width of view port
	float vpWidth = 100;
	m_start = std::pair<int, int>(1, 1);
	m_end = std::pair<int, int>(vpWidth-1, vpWidth-1);
	//renderer init
	m_rend.init(winSize, "Astar Threading");


	float aspectRatio = winSize.w / winSize.h;
	Size2D vpSize(vpWidth, vpWidth / aspectRatio);
	Point2D vpBottomLeft(-vpSize.w / 2, -vpSize.h / 2);

	//set up the viewport
	Rect vpRect(vpBottomLeft, vpSize);
	m_rend.setViewPort(vpRect);

	m_running = true;


	m_grid.init(static_cast<int>(vpWidth), vpSize,m_start, m_end);

	int data = NULL;
	SDL_Thread* thread = SDL_CreateThread(threadFunction, "grinf", &m_grid);


	SDL_DetachThread(thread);

	return true;
}
void Game::Update()
{
	m_grid.Update();

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
	m_grid.render(&m_rend);
	m_rend.present();
}


int threadFunction(void* data)
{
	Grid *g = (Grid*)data;

	while (g->getCurrent() != g->getEnd())
	{
		g->RunaStar();
	}

	return 0;
}

