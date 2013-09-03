#include "stdafx.h"
#include "Player.h"


Player::Player(void)
{
	position = sf::Vector2i(0, 0);
}

Player::Player(sf::Vector2i pos)
{
	position = pos;
}


Player::~Player(void)
{
}

sf::Vector2i Player::getPosition()
{
	return position;
}

void Player::setPosition(sf::Vector2i pos)
{
	position = pos;
}

void Player::move(sf::Vector2i offset)
{
	position += offset;
}
void Player::move(int x, int y)
{
	move(sf::Vector2i(x, y));
}
