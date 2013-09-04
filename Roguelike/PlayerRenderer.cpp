#include "stdafx.h"
#include "PlayerRenderer.h"


PlayerRenderer::PlayerRenderer(Player& playerIn) : player(playerIn)
{
	playerTexture.loadFromFile("image/player.png");
}


PlayerRenderer::~PlayerRenderer(void)
{
}

void PlayerRenderer::draw(sf::RenderTarget& target, sf::RenderStates states) const
{
	sf::Sprite sprite;
	sprite.setTexture(playerTexture);
	sprite.setPosition(player.getPosition().x * Game::TILE_SIZE, player.getPosition().y * Game::TILE_SIZE);
	target.draw(sprite);
}
