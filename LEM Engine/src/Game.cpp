#include "Game.h"
#include "GameState.h"
#include "MessageBus.h"

Game::Game() : _running(true), _framesPerSecond(60)
{
	std::cout << "Game Logic created." << std::endl;
}

Game::~Game()
{
	shutdown();
	std::cout << "Game Logic deleted." << std::endl;
}

bool Game::init()
{
	// Initialize message bus
	_messageBus = std::make_shared<MessageBus>(shared_from_this());
	if (!_messageBus->init())
		return false;

	// Also set the FPS if needed from editor options


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

	// ********************************************************* //
	// ********************* Fake messages ********************* //
	// ********************************************************* //

	Message consoleMsg(MessageType::Console, "Testing console printing.");
	_messageBus->postMessage(std::make_shared<Message>(consoleMsg));
	Message windowMsg(MessageType::CreateMainWindow, "Creating main window.");
	_messageBus->postMessage(std::make_shared<Message>(windowMsg));
	StringMessage imageMsg(MessageType::LoadBackground, "Loading a background image.", "Assets/Sprites/hello_world.bmp");
	_messageBus->postMessage(std::make_shared<StringMessage>(imageMsg));

	std::shared_ptr<StringMessage> delayedImageMsg = std::make_shared<StringMessage>(MessageType::LoadBackground, "Loading a second background image.", "Assets/Sprites/preview.png");
	//TimedMilliSecondsMessage timedMsg(MessageType::TimedMilliSecondsEvent, "Loading a background image after 5000ms.", 5000, delayedImageMsg);
	TimedSecondsMessage timedMsg(MessageType::TimedSecondsEvent, "Loading a background image after 3 seconds.", 3, delayedImageMsg);
	_messageBus->postMessage(std::make_shared<TimedSecondsMessage>(timedMsg));

	//Message quitMsg(MessageType::QuitGame, "Quit application.");
	//postMessage(std::make_unique<Message>(quitMsg));

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
	int simulatedTime = 0;
	while (_running)
	{
		int currentTime = std::clock();
		while (simulatedTime < currentTime)
		{
			simulatedTime += _framesPerSecond;
			_messageBus->pollMessages();
			_messageBus->updateSystems(); // Pass in frames per second as dt
		}

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

		// Temporarily shutdown to avoid dr.memory lockup
		//_running = false;
	}
}

void Game::handleMessages(const Message& message)
{
	switch (message.type)
	{
	case MessageType::QuitGame:
		_running = false;
		break;
	}
}













/* Legacy code */
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

//bool Game::finishedInput()
//{
//	// A new image path has been entered
//	return _inputEngine.getInputFinished();
//}

//bool Game::inputEnabled()
//{
//	return _inputEngine.getDisplayInputText();
//}
//
//bool Game::inputChanged()
//{
//	return _inputEngine.getInputChanged();
//}
//
//void Game::setInputChanged(const bool changed)
//{
//	_inputEngine.setInputChanged(changed);
//}
//
//std::string Game::getInputText()
//{
//	_inputEngine.setInputFinished(false);
//	return _inputEngine.getInputText();
//}
