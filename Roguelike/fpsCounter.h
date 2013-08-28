#pragma once
#include <string>
#include <SFML\System\Clock.hpp>
class FpsCounter
{
public:
	FpsCounter(void);
	~FpsCounter(void);
	void countFrame();
	float getFps();
private:
	float lastTime;
	float fps;
	sf::Clock clock;
};

