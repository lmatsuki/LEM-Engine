#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <SDL.h>

#include "Input.h"
#include "Graphics.h"
#include "AssetManager.h"

class GameState;

class Game : public std::enable_shared_from_this<Game>
{
public:
	Game();
	~Game();

	// Initialize SDL
	bool init();
	void shutdown();

	bool isRunning();
	void run();
	void handleMessages(std::shared_ptr<Message> & message);



	// GameState methods
	void pushState(std::unique_ptr<GameState> state);
	void popState();
	void changeState(std::unique_ptr<GameState> state);
	GameState* peekState();

	/********* Engine calls *********/
	// Graphics Engine
	bool loadImage(const std::string path);
	bool loadText(const std::string inputText);

	// Input Engine
	//bool finishedInput();
	//bool inputEnabled();
	//bool inputChanged();
	//void setInputChanged(const bool changed);
	//std::string getInputText();

	// engine parts
	//Input _inputEngine;
	//Graphics _graphicsEngine;
	AssetManager _assetManagerEngine;

private:
	// Properties
	bool _running;
	int _framesPerSecond;
	std::shared_ptr<MessageBus> _messageBus;

	std::stack<std::unique_ptr<GameState>> _states;
};