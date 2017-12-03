#include <iostream>
#include "Game.h"

int main(int, char**) 
{
	Game game;
	int status = game.init();	
	if (status != 0)
	{
		// There was an error intializing
		return status;
	}

	while (game.isRunning())
	{
		game.run();
	}	

	//std::cin.get();

	return 0;
}