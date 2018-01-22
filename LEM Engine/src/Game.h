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

	// Initialize the MessageBus.
	bool init();

	void shutdown();

	bool isRunning();

	void run();

	void handleMessages(const std::shared_ptr<const Message> & message);


private:
	bool _running;
	int _framesPerSecond; // Not const to allow changing during Play mode via editor.
	std::shared_ptr<MessageBus> _messageBus;






	/* Legacy code */
public:
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
	std::stack<std::unique_ptr<GameState>> _states;
};