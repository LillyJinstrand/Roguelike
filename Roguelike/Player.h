#pragma once
class Player
{
public:
	Player(void);
	explicit Player(sf::Vector2i);
	~Player(void);

	sf::Vector2i getPosition();
	void setPosition(sf::Vector2i);

	void move(sf::Vector2i);
	void move(int, int);
private:
	sf::Vector2i position;
};

