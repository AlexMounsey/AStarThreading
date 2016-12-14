#pragma once
#include "SDL.h"
#include "TileType.h"
#include "BasicType.h"
#include "Renderer.h"

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
	Tile();
	~Tile();
	void Init(float posX, float posY, float width, float height, tileType type);
	void Update();
	void render(Renderer * r);
	Point2D getPosition() const;
	Size2D getSize() const;
	tileType getType() const;
	void setType(tileType val);
	void setColour(Colour val);
};
