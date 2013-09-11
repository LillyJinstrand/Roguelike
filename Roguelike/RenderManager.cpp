#include "stdafx.h"
#include "RenderManager.h"

RenderManager::RenderManager()
{
	game = 0;
}


RenderManager::~RenderManager(void)
{
}

void RenderManager::setGame(Game *gameIn)
{
	game = gameIn;
}
void RenderManager::setMap(Map *mapIn)
{
	mapRenderer.setMap(mapIn);
}
void RenderManager::setPlayer(Player *playerIn)
{
	playerRenderer.setPlayer(playerIn);
}

void RenderManager::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	target.draw(mapRenderer);
	target.draw(playerRenderer);
}