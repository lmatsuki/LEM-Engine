#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <iostream>

class Graphics
{
public:
	Graphics();
	~Graphics();

	// Initialize the graphics engine
	bool init();

	// Load the resources
	bool load();	

	// This is called each frame
	void update();

	// Remove all resources
	void unload();

private:
	SDL_Window *gWindow;
	SDL_Surface *gScreenSurface;

	// Test PNG image
	SDL_Surface* optimizedSurface;
};