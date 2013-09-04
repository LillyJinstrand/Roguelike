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
	bool checkBounds(sf::Vector2i);

	bool isTileWalkable(sf::Vector2i);
private:
	std::vector<Tile> tiles;
	sf::Vector2i mapBounds;
};

