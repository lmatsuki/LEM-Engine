#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
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

	// Load from rendered text
	bool loadText(std::string inputText);

	// Get the text image dimensions
	int getTextWidth();
	int getTextHeight();

	// This is called each frame
	void render(std::string inputText = "");

	// This shows debug text
	void renderText(std::string inputText, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Remove all resources
	void unload();

private:
	SDL_Window *gWindow;
	SDL_Renderer *gRenderer;
	SDL_Texture *gTexture;
	int _screenWidth;
	int _screenHeight;
	
	// Used for text input
	SDL_Texture *gInputTextTexture;
	SDL_Color textColor;
	TTF_Font *gFont;
	int _textWidth;
	int _textHeight;
};