#include "Game.h"
#include "GameState.h"

Game::Game() : _running(true)
{
	
}

Game::~Game()
{
	//shutdown();
}

bool Game::init()
{
	// Initialize message bus
	_messageBus = std::make_shared<MessageBus>();
	if (!_messageBus->init())
		return false;

	// Initialize engine components
	//std::cout << "Initializing SDL.." << std::endl;
	//if (!_graphicsEngine.init())
	//{
	//	return 1;
	//}
	//else if (!_assetManagerEngine.init())
	//{
	//	return 2;
	//}

	//// Temporarily load the scene
	//if (!_graphicsEngine.load())
	//{
	//	return 3;
	//}

	//std::cout << "SDL initialized!" << std::endl;
	//_running = true;
	return true;
}

void Game::shutdown()
{
	//_graphicsEngine.unload();

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
		_messageBus->pollMessages();
		_messageBus->updateSystems();

		// TO DO... Implement clock 		

		//if (peekState() == nullptr)
		//	continue;

		//if (_inputEngine.exitScene())
		//{
		//	_running = false;
		//	return;
		//}

		//// Process input
		//_inputEngine.update();
		//peekState()->handleInput();
		//
		//// Process logic
		//peekState()->update();

		//// Render graphics
		//_graphicsEngine.render();
		//peekState()->render();
		//if (_inputEngine.getDisplayInputText())
		//	_graphicsEngine.renderText(_inputEngine.getInputText());
		//_graphicsEngine.updateScreen();


		//// Run save command (test)
		//if (_assetManagerEngine.executeSave)
		//	_assetManagerEngine.saveAllSprites();
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

bool Game::loadImage(const std::string path)
{
	//return _graphicsEngine.loadImage(path);
	return false;
}

bool Game::loadText(const std::string inputText)
{
	//return _graphicsEngine.loadText(inputText);
	return false;
}

bool Game::finishedInput()
{
	// A new image path has been entered
	return _inputEngine.getInputFinished();
}

bool Game::inputEnabled()
{
	return _inputEngine.getDisplayInputText();
}

bool Game::inputChanged()
{
	return _inputEngine.getInputChanged();
}

void Game::setInputChanged(const bool changed)
{
	_inputEngine.setInputChanged(changed);
}

std::string Game::getInputText()
{
	_inputEngine.setInputFinished(false);
	return _inputEngine.getInputText();
}
