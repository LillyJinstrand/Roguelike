#pragma once
#include "DebugOverlay.h"
#include "fpsCounter.h"
#include "Map.h"
#include "MapRenderer.h"
#include <string>
class Game
{
public:
	Game(void);
	~Game(void);
	void start(); //Start the gameloop
private:
	enum GameState
	{
		UNINITIALIZED,
		SPLASH_SCREEN,
		MENU,
		RUNNING,
		PAUSED,
		EXITING
	};

	void init(); //Load resources
	void gameloop(); //The main gameloop
	void cleanup(); //Unload resources

	void update(); //Updates the game logic
	void draw(); //Draws the screen

	GameState gameState;
	sf::RenderWindow window;
	DebugOverlay debugOverlay;
	FpsCounter fpsCounter;

	Map map;
	MapRenderer mapRenderer;

	sf::Clock clock;
	int lastTime;
	int skippedFrames;

	std::string fpsString;
	std::string frameSkipString;

	static const int TARGET_FRAMETIME = 16; //In milliseconds
};

