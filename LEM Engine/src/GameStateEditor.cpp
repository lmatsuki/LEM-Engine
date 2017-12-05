#include "GameStateEditor.h"

GameStateEditor::GameStateEditor(std::weak_ptr<Game> game) : GameState(game)
{

}

GameStateEditor::~GameStateEditor()
{
}

void GameStateEditor::handleInput()
{
	std::cout << "handling game editor input" << std::endl;
}

void GameStateEditor::update()
{
	std::cout << "updating game editor" << std::endl;
}

void GameStateEditor::render()
{
	std::cout << "rendering game editor" << std::endl;
}
