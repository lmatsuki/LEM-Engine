#pragma once

#include <iostream>
#include <SDL.h>

#include "Input.h"
#include "Graphics.h"
#include "AssetManager.h"

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

private:
	// class properties
	bool _running;

	// engine parts
	Input inputEngine;
	Graphics graphicsEngine;
	AssetManager assetManagerEngine;
};