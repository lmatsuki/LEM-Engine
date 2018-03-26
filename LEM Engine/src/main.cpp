#include <iostream>
#include "Game.h"
//#include "GameStateEditor.h"
//#include "Test.h"

int main(int, char**) 
{
	// Create the Game shared_ptr
	//std::shared_ptr<Game> gameSharedPtr = std::make_shared<Game>();

	//int status = gameSharedPtr->init();
	//if (status != 0)
	//{
	//	// There was an error intializing
	//	return status;
	//}

	// Load the Editor GameState
	//std::weak_ptr<Game> gameWeakPtr = std::weak_ptr<Game>(gameSharedPtr);
	//std::unique_ptr<GameStateEditor> editorGameState = std::make_unique<GameStateEditor>(gameWeakPtr);
	//gameSharedPtr->pushState(std::move(editorGameState));

	//while (gameSharedPtr->isRunning())
	//{
	//	gameSharedPtr->run();
	//}	

	// To run and verify deeper C++ understanding
	//Test test;
	//test.runGame();

	// The game class uses enable_shared_from_this, so we need to create a share_ptr here
	std::shared_ptr<Game> game = std::make_shared<Game>();
	if (game.get()->init())
		game.get()->run();

	//std::cin.get();


	




	return 0;
}