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
	void listCurrentFiles(); // Temporary function to test class

private:
	std::vector<std::string> _spriteFilenames;
};