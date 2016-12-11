#include "Tile.h"

Tile::Tile()
{

}

Tile::~Tile()
{

}

void Tile::Init(float posX, float posY, float width, float height, tileType type)
{
	m_rect.pos.x = posX;
	m_rect.pos.y = posY;
	m_rect.size.w = width;
	m_rect.size.h = height;
	m_type = type;
	
	switch (m_type)
	{
	case tileType::WALL:
		m_colour = { 0, 0, 0, 255 };
		break;
	case tileType::TILE:
		m_colour = { 100, 100, 200, 255 };
		break;
	}
}


void Tile::Update()
{

}

void Tile::render(Renderer * r)
{
	r->drawWorldFillRect(m_rect, m_colour);
}
void Tile::setColour(Colour val)
{
	m_colour = val;
}
Point2D Tile::getPosition() const
{
	return Point2D(m_rect.pos.x, m_rect.pos.y);
}

Size2D Tile::getSize() const
{
	return Size2D(m_rect.size.w, m_rect.size.h);
}

tileType Tile::getType() const
{
	return m_type;
}

void Tile::setType(tileType val)
{
	m_type = val;
}

