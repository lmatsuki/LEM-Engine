#include "GameState.h"

GameState::GameState()
{
}

GameState::GameState(std::weak_ptr<Game> game) : _game(game)
{

}

GameState::~GameState()
{
}

void GameState::handleInput()
{
}

void GameState::update()
{
}

void GameState::render()
{
}
