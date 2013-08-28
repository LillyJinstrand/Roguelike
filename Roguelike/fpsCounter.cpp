#include "stdafx.h"
#include "fpsCounter.h"


FpsCounter::FpsCounter(void)
{
	lastTime = 0.0f;
	fps = 0.0f;
	clock.restart();
}


FpsCounter::~FpsCounter(void)
{
}

void FpsCounter::countFrame()
{
	float currentTime = clock.getElapsedTime().asSeconds();
    fps = 1.0f / (currentTime - lastTime);
    lastTime = currentTime;
}

float FpsCounter::getFps()
{
	return fps;
}
