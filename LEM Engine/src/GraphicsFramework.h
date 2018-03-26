#pragma once

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <map>
#include <memory>
#include <iostream>
#include <vector>
#include <algorithm>
#include "IFramework.h"
#include "ImageData.h"

class GraphicsFramework : public IFramework
{
public:
	GraphicsFramework();
	~GraphicsFramework();

	// Initialize the graphics engine
	const StatusCode init();

	virtual const std::string & getFrameworkName() override;

	/***************************************************************/
	/****************** Methods called by Systems ******************/
	/***************************************************************/
	bool createMainWindow(const std::string & windowName = "");
	bool storeImage(const std::string & filename, std::unique_ptr<ImageData> imageData);
	bool renderImage(const std::string & filename);
	// Find and remove the image from the renderList by the filename.
	bool unrenderImage(const std::string & filename);
	bool loadImage(const std::string & path);


	// This is called each frame
	void render();

private:
	int _screenWidth;
	int _screenHeight;
	// Filename to unique_ptr of ImageData
	std::unique_ptr<std::map<std::string, std::unique_ptr<ImageData>>> _imageDataDict;
	// Filenames to render
	std::vector<std::string> _renderList;

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