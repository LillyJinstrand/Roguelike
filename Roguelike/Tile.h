#pragma once
#include <SFML/System/Vector2.hpp>
class Tile
{
public:
	Tile(void);
	explicit Tile(int id);
	~Tile(void);

	int getTileId();
private:
	int tileId;
};

