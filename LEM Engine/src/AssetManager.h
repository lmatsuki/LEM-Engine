#pragma once

#include <iostream>
#include <vector>
#include <SDL.h>

class AssetManager
{
public:
	AssetManager();
	~AssetManager();

	bool init();
	void insertSprite(const std::string spriteFilepath);

	void saveAllSprites();

	void listCurrentFiles(); // Temporary function to test class

	bool executeSave = false; // temp

private:
	//std::vector<std::string> _spriteFilenames;	
	std::string _spriteFilenames[10];
};