#include "stdafx.h"
#include "Game.h"


Game::Game(void) : window(sf::VideoMode(800, 600), "Roguelike"), mapRenderer(map)
{
	skippedFrames = 0;
}


Game::~Game(void)
{
}

void Game::start()
{
	init();
	while(gameState != GameState::EXITING)
	{
		gameloop();
	}
	cleanup();
}

void Game::init()
{
	debugOverlay.addString(&fpsString);
	debugOverlay.addString(&frameSkipString);
	map.create(20, 30);
	lastTime = 0;
	clock.restart();
	gameState = GameState::RUNNING;
}

void Game::gameloop()
{
	update();
	if(clock.getElapsedTime().asMilliseconds() - lastTime > TARGET_FRAMETIME)
	{
		skippedFrames++;
	}
	else
	{
		draw();
		skippedFrames = 0;
	}
	if(clock.getElapsedTime().asMilliseconds() - lastTime < TARGET_FRAMETIME)
	{
		Sleep(TARGET_FRAMETIME - (clock.getElapsedTime().asMilliseconds() - lastTime));
	}
	lastTime = clock.getElapsedTime().asMilliseconds();
}

void Game::cleanup()
{

}

void Game::update()
{
	fpsString = std::string("FPS: ") + std::to_string(floor(fpsCounter.getFps()));
	frameSkipString = std::string("Skipped Frames: ") + std::to_string(skippedFrames);
	switch (gameState)
	{
	case Game::UNINITIALIZED:
		break;
	case Game::SPLASH_SCREEN:
		break;
	case Game::MENU:
		break;
	case Game::RUNNING:
		sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
			{
				gameState = GameState::EXITING;
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::F3)
			{
				debugOverlay.toggleVisible();
			}
        }
		break;
	case Game::PAUSED:
		break;
	case Game::EXITING:
		break;
	default:
		//This should never happen
		break;
	}
}

void Game::draw()
{
	window.clear();
	switch (gameState)
	{
	case Game::UNINITIALIZED:
		break;
	case Game::SPLASH_SCREEN:
		break;
	case Game::MENU:
		break;
	case Game::RUNNING:
		window.draw(mapRenderer);
		break;
	case Game::PAUSED:
		break;
	case Game::EXITING:
		break;
	default:
		//This should never happen
		break;
	}
	window.draw(debugOverlay);
    window.display();
	fpsCounter.countFrame();
}