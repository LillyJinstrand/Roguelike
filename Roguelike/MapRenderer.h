#pragma once
#include "Map.h"
class MapRenderer : public sf::Drawable
{
public:
	MapRenderer(Map &);
	~MapRenderer(void);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	Map &map;

	sf::Texture floorTexture;

};