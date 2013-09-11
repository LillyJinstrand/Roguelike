#pragma once
#include "Game.h"
#include "PlayerRenderer.h"
#include "MapRenderer.h"
class RenderManager :
	public sf::Drawable
{
public:
	RenderManager();
	~RenderManager(void);
	void setGame(Game*);
	void setMap(Map*);
	void setPlayer(Player*);
	
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	Game *game;
	MapRenderer mapRenderer;
	PlayerRenderer playerRenderer;
};

