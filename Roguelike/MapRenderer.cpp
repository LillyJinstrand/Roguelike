#include "stdafx.h"
#include "MapRenderer.h"


MapRenderer::MapRenderer(Map &mapIn) : map(mapIn)
{
	floorTexture.loadFromFile("image/floor.png");
}


MapRenderer::~MapRenderer(void)
{
}

void MapRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite;
	sprite.setTexture(floorTexture);
	for(int x=0; x < map.getBounds().x; x++)
	{
		for(int y=0; y < map.getBounds().y; y++)
		{
			sprite.setPosition((float)Game::TILE_SIZE * x, (float)Game::TILE_SIZE * y);
			target.draw(sprite);
		}
	}
}
