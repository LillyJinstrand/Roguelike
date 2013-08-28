#include "stdafx.h"
#include "MapRenderer.h"


MapRenderer::MapRenderer(Map &mapIn) : map(mapIn)
{
	floor.loadFromFile("image/floor.png");
	floorTexture.loadFromImage(floor);
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
			sprite.setPosition(floorTexture.getSize().x * x, floorTexture.getSize().y * y);
			target.draw(sprite);
		}
	}
}
