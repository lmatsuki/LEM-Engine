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

	// Add the Editor GameState to the game
	//std::shared_ptr<Game> gameSharedPtr = shared_from_this();
	//std::weak_ptr<Game> gameWeakPtr = std::weak_ptr<Game>(gameSharedPtr);
	//std::unique_ptr<GameState> editorGameState = std::make_unique<GameStateEditor>(gameWeakPtr);
	//pushState(std::move(editorGameState));

	std::cout << "Success!" << std::endl;
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

		//if (this->_states.empty())
		if (peekState() == nullptr)
			continue;

		peekState()->handleInput();
		peekState()->update();
		peekState()->render();
	}


	// Process input
	//_inputEngine.update();
	//if (_inputEngine.exitScene())
	//	_running = false;

	//// Process logic


	//// Update graphics
	//_graphicsEngine.render(_inputEngine.getInputText());


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