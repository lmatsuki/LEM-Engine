#pragma once

#include <memory>
#include "Game.h"

class GameState
{
public:
	GameState();
	GameState(std::weak_ptr<Game> game);
	virtual ~GameState();

	virtual void handleInput();
	virtual void update();
	virtual void render();

	// The instance of the game that holds this GameState
	std::weak_ptr<Game> _game;
};