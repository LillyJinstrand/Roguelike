#pragma once
#include "Tile.h"
class Map
{
public:
	Map(void);
	~Map(void);

	void create(int, int);

	Tile getTile(sf::Vector2i);
	sf::Vector2i getBounds();


private:
	std::vector<Tile> tiles;
	sf::Vector2i mapBounds;
};

