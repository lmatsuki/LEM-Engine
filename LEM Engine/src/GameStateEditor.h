#pragma once

#include "GameState.h"

class GameStateEditor : public GameState
{
public:
	GameStateEditor(std::weak_ptr<Game> game);
	~GameStateEditor();

	virtual void handleInput();
	virtual void update();
	virtual void render();

private:

};