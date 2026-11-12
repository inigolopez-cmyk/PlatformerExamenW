#include "Stair.h"

Stair::Stair(float x, float y, float size):
	Tile(x, y, size)
{
	SetType(TileType::Stair);
}

Stair::~Stair()
{
}

void Stair::Draw() const
{
	Color transparentColor = Fade(GREEN, 0.1f);
	DrawRectangle(position.x, position.y, size, size, transparentColor);
}