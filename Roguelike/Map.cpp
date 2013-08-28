#include "stdafx.h"
#include "Map.h"


Map::Map(void)
{
}


Map::~Map(void)
{
}

void Map::create(int xSizeIn, int ySizeIn)
{
	mapBounds.x = xSizeIn;
	mapBounds.y = ySizeIn;
	for(int x=0; x < mapBounds.x; x++)
	{
		for(int y=0; y < mapBounds.y; y++)
		{
			tiles.push_back(Tile(1));
		}
	}
}

Tile Map::getTile(sf::Vector2i position)
{
	return tiles[(position.x * mapBounds.y) + position.y];
}

sf::Vector2i Map::getBounds()
{
	return mapBounds;
}