#include "Game.h"
#include "GameState.h"

Game::Game() : _running(true)
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
	if (!_graphicsEngine.init())
	{
		return 1;
	}
	else if (!_assetManagerEngine.init())
	{
		return 2;
	}

	// Temporarily load the scene
	if (!_graphicsEngine.load())
	{
		return 3;
	}

	std::cout << "SDL initialized!" << std::endl;
	_running = true;
	return 0;
}

void Game::shutdown()
{
	_graphicsEngine.unload();

	std::cout << "Shutting down SDL.." << std::endl;	
	SDL_Quit();
}

bool Game::isRunning()
{
	return _running;
}

void Game::run()
{
	while (_running)
	{
		// TO DO... Implement clock 


		if (peekState() == nullptr)
			continue;

		if (_inputEngine.exitScene())
		{
			_running = false;
			return;
		}

		// Process input
		_inputEngine.update();
		peekState()->handleInput();
		
		// Process logic
		peekState()->update();

		// Render graphics
		_graphicsEngine.render();
		peekState()->render();
		if (_inputEngine.getInputTextEnabled())
			_graphicsEngine.renderText(_inputEngine.getInputText());
		_graphicsEngine.updateScreen();
	}

	// Temporarily shutdown to avoid dr.memory lockup
	//_running = false;
}

void Game::pushState(std::unique_ptr<GameState> state)
{
	this->_states.push(std::move(state));
}

void Game::popState()
{
	this->_states.top().reset();
	this->_states.pop();
}

void Game::changeState(std::unique_ptr<GameState> state)
{
	if (!this->_states.empty())
		popState();
	pushState(std::move(state));
}

GameState* Game::peekState()
{
	if (this->_states.empty())
		return nullptr;
	return this->_states.top().get();
}

bool Game::loadImage(std::string path)
{
	return _graphicsEngine.loadImage(path);
}