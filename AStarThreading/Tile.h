#pragma once
#include "SDL.h"
#include "TileType.h"
#include "BasicType.h"
#include "Renderer.h"
#include <vector>
#include <queue>

class Tile
{
private:
	// Holds Position of Block on Screen
	Rect m_rect;
	Colour m_colour;
	tileType m_type;
	int g; 
	int h;
	//g + h =f


public:
	Tile(int,int);
	~Tile();
	void Init(float posX, float posY, float width, float height, tileType type);
	void Update();
	void render(Renderer * r);
	std::pair<int, int> getPosition() const;
	Size2D getSize() const;
	tileType getType() const;
	void setType(tileType val);
	bool operator<(const Tile &tile) const;
	bool operator==(const Tile & t) const;
	void setColour(Colour val);
	void costOfTile(std::pair<int, int>, std::pair<int, int>);

	
};
