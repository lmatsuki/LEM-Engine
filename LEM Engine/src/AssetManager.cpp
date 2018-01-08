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

	// Get list of sprites from binary file
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
		//int fileCount = _spriteFilenames.size();
		int fileCount = 10;
		for (int i = 0; i < fileCount; i++)
		{
			SDL_RWread(file, &_spriteFilenames[i], sizeof(std::string), fileCount);
		}

		//Close file handler
		SDL_RWclose(file);
	}

	std::cout << "Initialized Asset Manager." << std::endl;

	// Temporarily add test sprites here
	insertSprite("Assets/Sprites/preview.png");
	std::cout << "Added temporary sprites to SpriteFilenames." << std::endl;

	return success;
}

void AssetManager::insertSprite(const std::string spriteFilepath)
{
	//_spriteFilenames.push_back(spriteFilepath);
	//_spriteFilenames[0] = spriteFilepath;
}

void AssetManager::saveAllSprites()
{
	//Create file for writing
	SDL_RWops* file = SDL_RWFromFile("Assets/Sprites/sprites.bin", "w+b");
	if (file != NULL)
	{
		printf("New file created for saving.\n");
		//int fileCount = _spriteFilenames.size();
		int fileCount = _spriteFilenames->length();
		for (int i = 0; i < fileCount; i++)
		{
			SDL_RWwrite(file, &_spriteFilenames[i], sizeof(std::string), 1);
		}

		//Close file handler
		SDL_RWclose(file);
	}
}

void AssetManager::listCurrentFiles()
{
	/*int fileCount = _spriteFilenames.size();*/
	int fileCount = _spriteFilenames->length();
	std::cout << "List of sprites:" << std::endl;

	for (int i = 0; i < fileCount; i++)
	{
		std::cout << _spriteFilenames[i].c_str() << std::endl;
	}
}