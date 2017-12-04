#include "Graphics.h"

Graphics::Graphics() : _screenWidth(800), _screenHeight(600), gWindow(NULL), gRenderer(NULL), gTexture(NULL), gInputTextTexture(NULL),
	textColor({ 0, 0, 0, 0xFF }), gFont(NULL), _textWidth(0), _textHeight(0)
{
}

Graphics::~Graphics()
{
	//Destroy window   
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
	gRenderer = NULL;

	TTF_Quit();
	IMG_Quit();
}

bool Graphics::init()
{
	// Initialize SDL VIDEO
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return false;
	}

	//Create window
	gWindow = SDL_CreateWindow("LEM Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		return false;
	}
	else
	{
		// Create renderer for window
		gRenderer = SDL_CreateRenderer(gWindow, -1, SDL_RENDERER_ACCELERATED);
		if (gRenderer == NULL)
		{
			std::cout << "Renderer could not be created! SDL Error: " << SDL_GetError() << std::endl;
			return false;
		}
		else
		{
			//Initialize renderer color
			SDL_SetRenderDrawColor(gRenderer, 0xFF, 0xFF, 0xFF, 0xFF);

			//Initialize PNG loading
			int imgFlags = IMG_INIT_PNG;
			if (!(IMG_Init(imgFlags) & imgFlags))
			{
				std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
				return false;
			}

			//Initialize SDL_ttf
			if (TTF_Init() == -1)
			{
				std::cout << "SDL_ttf could not initialize! SDL_ttf Error: " << TTF_GetError() << std::endl;
				return false;
			}
		}
	}

	return true;
}

bool Graphics::load()
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load("Assets/Sprites/preview.png");
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image %s! SDL_image Error: " << "Assets/Sprites/preview.png" << IMG_GetError() << std::endl;
	}
	else
	{
		//Create texture from surface pixels
		gTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (gTexture == NULL)
		{
			std::cout << "Unable to create texture from: " << "Assets/Sprites/preview.png" << SDL_GetError() << std::endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	// Load the font
	gFont = TTF_OpenFont("lazy.ttf", 28);
	if (gFont == NULL)
	{
		std::cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return false;
	}

	return true;
}

bool Graphics::loadText(std::string inputText)
{
	//Load text texture
	SDL_Surface* textSurface = TTF_RenderText_Solid(gFont, inputText.c_str(), textColor);
	if (textSurface != NULL)
	{
		//Create texture from surface pixels
		gInputTextTexture = SDL_CreateTextureFromSurface(gRenderer, textSurface);
		if (gInputTextTexture == NULL)
		{
			std::cout << "Unable to create texture from rendered text! SDL Error: " << SDL_GetError() << std::endl;
		}
		else
		{
			//Get image dimensions
			_textWidth = textSurface->w;
			_textHeight = textSurface->h;
		}

		//Get rid of old surface
		SDL_FreeSurface(textSurface);
	}
	else
	{
		std::cout << "Unable to render text surface! SDL_ttf Error: " << TTF_GetError() << std::endl;
	}

	return false;
}

int Graphics::getTextWidth()
{
	return _textWidth;
}

int Graphics::getTextHeight()
{
	return _textHeight;
}

void Graphics::render(std::string inputText)
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	//Render texture to screen
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);

	// Render text
	renderText(inputText);

	//Update screen
	SDL_RenderPresent(gRenderer);
}

void Graphics::renderText(std::string inputText, SDL_Rect* clip, double angle, SDL_Point* center, SDL_RendererFlip flip)
{
	//Text is not empty
	if (inputText != "")
	{
		//Render new text
		loadText(inputText);
	}
	//Text is empty
	else
	{
		//Render space texture
		loadText(" ");
	}

	//Set rendering space and render to screen
	SDL_Rect renderQuad = { (_screenWidth - getTextWidth()) / 2, getTextHeight(), getTextWidth(), getTextHeight() };

	//Set clip rendering dimensions
	if (clip != NULL)
	{
		renderQuad.w = clip->w;
		renderQuad.h = clip->h;
	}

	//Render to screen
	SDL_RenderCopyEx(gRenderer, gInputTextTexture, clip, &renderQuad, angle, center, flip);
}

void Graphics::unload()
{
	//Free loaded image
	SDL_DestroyTexture(gTexture);
	gTexture = NULL;
	gInputTextTexture = NULL;

	// Free font
	TTF_CloseFont(gFont);
	gFont = NULL;
}
