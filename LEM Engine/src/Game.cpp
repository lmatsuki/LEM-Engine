#include "Game.h"

Game::Game() : _running(false)
{
	
}

Game::~Game()
{
	shutdown();
}

int Game::init()
{
	// Initialize engine components
	std::cout << "Initializing SDL.." << std::endl;
	if (!graphicsEngine.init())
	{
		return 1;
	}
	else if (!assetManagerEngine.init())
	{
		return 2;
	}

	// Temporarily load the scene
	if (!graphicsEngine.load())
	{
		return 3;
	}

	std::cout << "Success!" << std::endl;
	_running = true;
	return 0;
}

void Game::shutdown()
{
	graphicsEngine.unload();

	std::cout << "Shutting down SDL.." << std::endl;	
	SDL_Quit();
}

bool Game::isRunning()
{
	return _running;
}

void Game::run()
{
	// Process input
	inputEngine.update();
	if (inputEngine.exitScene())
		_running = false;

	// Process logic


	// Update graphics
	graphicsEngine.update();


	// Temporarily shutdown to avoid dr.memory lockup
	//_running = false;
}