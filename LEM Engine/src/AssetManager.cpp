#include "AssetManager.h"

AssetManager::AssetManager()
{
}

AssetManager::~AssetManager()
{
}

bool AssetManager::init()
{
	// Loading success flag
	bool success = true;

	// Get list of sprites fomr binary file
	SDL_RWops* file = SDL_RWFromFile("Assets/Sprites/sprites.bin", "r+b");

	//File does not exist
	if (file == NULL)
	{
		printf("Warning: Unable to open file! SDL Error: %s\n", SDL_GetError());

		//Create file for writing
		file = SDL_RWFromFile("Assets/Sprites/sprites.bin", "w+b");
		if (file != NULL)
		{
			printf("New file created!\n");

			//Close file handler
			SDL_RWclose(file);
		}
		else
		{
			printf("Error: Unable to create file! SDL Error: %s\n", SDL_GetError());
			success = false;
		}
	}
	//File exists
	else
	{
		//Load data
		printf("Reading file...!\n");
		int fileCount = _spriteFilenames.size();
		for (int i = 0; i < fileCount; i++)
		{
			SDL_RWread(file, &_spriteFilenames[i], sizeof(std::string), 1);
		}

		//Close file handler
		SDL_RWclose(file);
	}

	std::cout << "Initialized Asset Manager." << std::endl;
	return success;
}

void AssetManager::listCurrentFiles()
{

}