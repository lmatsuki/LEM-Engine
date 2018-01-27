#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>
#include <memory>
#include <iostream>
#include "Framework.h"

class Graphics : public Framework
{
public:
	Graphics();
	~Graphics();

	// Initialize the graphics engine
	const StatusCode init();

	virtual const std::string & getFrameworkName() override;

	/***************************************************************/
	/****************** Methods called by Systems ******************/
	/***************************************************************/
	bool createMainWindow();
	bool storeImage(const std::string & path, const std::string & name);
	bool renderImage(const std::string & name);
	bool loadImage(const std::string & path);


	// This is called each frame
	void render();

private:
	int _screenWidth;
	int _screenHeight;
	std::unique_ptr<std::map<std::string, SDL_Texture*>> sdlTextureDict;	
	SDL_Window * gWindow;
	SDL_Renderer *gRenderer;
	SDL_Texture *gTexture;







	// Legacy Code ///
public:
	// Load the resources
	
	bool load();	

	// Load from rendered text
	bool loadText(std::string inputText);

	// Get the text image dimensions
	int getTextWidth();
	int getTextHeight();



	// This shows debug text
	void renderText(std::string inputText, SDL_Rect* clip = NULL, double angle = 0.0, SDL_Point* center = NULL, SDL_RendererFlip flip = SDL_FLIP_NONE);

	// Updates the screen with current surface/textures
	void updateScreen();

	// Remove all resources
	void unload();

private:
	// Used for text input
	SDL_Texture *gInputTextTexture;
	SDL_Color textColor;
	TTF_Font *gFont;
	int _textWidth;
	int _textHeight;
};