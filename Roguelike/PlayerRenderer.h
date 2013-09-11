#pragma once
#include "Player.h"
#include "Game.h"
class PlayerRenderer : public sf::Drawable
{
public:
	PlayerRenderer();
	explicit PlayerRenderer(Player*);
	~PlayerRenderer(void);

	void setPlayer(Player*);
private:
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	sf::Texture playerTexture;

	Player *player;
};

