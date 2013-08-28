#include "stdafx.h"
#include "Tile.h"


Tile::Tile(void)
{
}

Tile::Tile(int id)
{
	tileId = id;
}


Tile::~Tile(void)
{
}

int Tile::getTileId()
{
	return tileId;
}
