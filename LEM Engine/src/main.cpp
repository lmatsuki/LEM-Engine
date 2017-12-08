#include <iostream>
#include "Game.h"
#include "GameStateEditor.h"


int main(int, char**) 
{
	// Create the Game shared_ptr
	std::shared_ptr<Game> gameSharedPtr = std::make_shared<Game>();

	int status = gameSharedPtr->init();
	if (status != 0)
	{
		// There was an error intializing
		return status;
	}

	// Load the Editor GameState
	std::weak_ptr<Game> gameWeakPtr = std::weak_ptr<Game>(gameSharedPtr);
	std::unique_ptr<GameStateEditor> editorGameState = std::make_unique<GameStateEditor>(gameWeakPtr);
	gameSharedPtr->pushState(std::move(editorGameState));

	while (gameSharedPtr->isRunning())
	{
		gameSharedPtr->run();
	}	

	//std::cin.get();

	




	return 0;
}