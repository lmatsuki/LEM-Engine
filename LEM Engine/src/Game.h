#pragma once

#include <iostream>
#include <memory>
#include <stack>
#include <SDL.h>

#include "Input.h"
#include "Graphics.h"
#include "AssetManager.h"

class GameState;

class Game
{
public:
	Game();
	~Game();

	// Initialize SDL
	int init();
	void shutdown();

	bool isRunning();
	void run();

	// GameState methods
	void pushState(std::unique_ptr<GameState> state);
	void popState();
	void changeState(std::unique_ptr<GameState> state);
	GameState* peekState();


private:
	// Properties
	bool _running;
	std::stack<std::unique_ptr<GameState>> _states;

	// engine parts
	Input _inputEngine;
	Graphics _graphicsEngine;
	AssetManager _assetManagerEngine;

};