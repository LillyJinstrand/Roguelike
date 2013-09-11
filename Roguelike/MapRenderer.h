#pragma once
#include "Map.h"
#include "Game.h"
class MapRenderer : public sf::Drawable
{
public:
	MapRenderer();
	explicit MapRenderer(Map*);
	~MapRenderer(void);

	void setMap(Map*);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Map *map;

	sf::Texture floorTexture;

};