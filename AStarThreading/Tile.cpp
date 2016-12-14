#include "Tile.h"

Tile::Tile(int x,int y)
{
	m_rect.pos.x = x;
	m_rect.pos.y = y;
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
	

}


void Tile::Update()
{

}

void Tile::render(Renderer * r)
{
	switch (m_type)
	{
	case tileType::PATH:
		m_colour = { 255,165,0, 255 };
		break;
	case tileType::START:
		m_colour = { 0, 255, 0, 255 };
		break;
	case tileType::END:
		m_colour = { 255, 0, 0, 255 };
		break;
	}
	r->drawWorldFillRect(m_rect, m_colour);
}
void Tile::setColour(Colour val)
{
	m_colour = val;
}
void Tile::costOfTile(std::pair<int, int> start, std::pair<int, int> end)
{
	g = sqrt((m_rect.pos.x - start.first) * (m_rect.pos.x - start.first)) + sqrt((m_rect.pos.y - start.second) * (m_rect.pos.y - start.second));
	h = sqrt((m_rect.pos.x - end.first) * (m_rect.pos.x - end.first)) + sqrt((m_rect.pos.y - end.second) * (m_rect.pos.y- end.second));
}
std::pair<int, int> Tile::getPosition() const
{
	return std::pair<int, int>(m_rect.pos.x, m_rect.pos.y);
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

bool Tile::operator<(const Tile & tile) const
{
	return h + g > tile.h + tile.g;
}


bool Tile::operator==(const Tile & t) const
{

	if ((m_rect.pos.x == t.getPosition().first) && (m_rect.pos.y == t.getPosition().second))
	{
		return true;
	}
	else {
		return false;
	}
}

