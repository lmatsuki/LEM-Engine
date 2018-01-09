#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <memory>
#include <iostream>
#include "Framework.h"

class Graphics : public Framework
{
public:
	Graphics(std::shared_ptr<MessageBus> messageBus, std::string frameworkName);
	~Graphics();

	void handleMessages(Message message);

	// Initialize the graphics engine
	bool init();

	// Load the resources
	bool loadImage(std::string path);
	bool load();	

	// Load from rendered text
	bool loadText(std::string inputText);

	// Get the text image dimensions
	int getTextWidth();
	int getTextHeight();

	// This is called each frame
	void render();

	// This shows debug text
	void renderText(std::string inputText, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Updates the screen with current surface/textures
	void updateScreen();

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