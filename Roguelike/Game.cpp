#include "stdafx.h"
#include "Game.h"


Game::Game(void) : window(sf::VideoMode(800, 600), "Roguelike"), mapRenderer(map) , playerRenderer(player)
{
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
	map.create(10, 5);
	worldView.setSize(800, 600);
	worldView.setCenter(400, 300);
	skippedFrames = 0;
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
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::W)
			{
				player.move(0, -1);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::S)
			{
				player.move(0, 1);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::A)
			{
				player.move(-1, 0);
			}
			if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::D)
			{
				player.move(1, 0);
			}
        }
		worldView.setCenter(sf::Vector2f(player.getPosition().x * Game::TILE_SIZE, player.getPosition().y * Game::TILE_SIZE));
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
	window.setView(worldView);
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
		window.draw(playerRenderer);
		break;
	case Game::PAUSED:
		break;
	case Game::EXITING:
		break;
	default:
		//This should never happen
		break;
	}
	window.setView(window.getDefaultView());
	window.draw(debugOverlay);
    window.display();
	fpsCounter.countFrame();
}