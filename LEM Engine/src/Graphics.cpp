#include "Graphics.h"

Graphics::Graphics() : optimizedSurface(NULL)
{
}

Graphics::~Graphics()
{
	SDL_DestroyWindow(gWindow);
	gWindow = NULL;
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
	gWindow = SDL_CreateWindow("LEM Engine", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 800, 600, SDL_WINDOW_SHOWN);
	if (gWindow == NULL)
	{
		return false;
	}
	else
	{
		//Initialize PNG loading
		int imgFlags = IMG_INIT_PNG;
		if (!(IMG_Init(imgFlags) & imgFlags))
		{
			std::cout << "SDL_image could not initialize! SDL_image Error: " << IMG_GetError() << std::endl;
			return false;
		}
		else
		{
			//Get window surface
			gScreenSurface = SDL_GetWindowSurface(gWindow);
			return true;
		}
	}
}

bool Graphics::load()
{
	//Load image at specified path (PNG)
	SDL_Surface* loadedSurface = IMG_Load("Assets/Sprites/preview.png");
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image %s! SDL_image Error: " << IMG_GetError() << std::endl;
	}
	else
	{
		//Convert surface to screen format
		optimizedSurface = SDL_ConvertSurface(loadedSurface, gScreenSurface->format, NULL);
		if (optimizedSurface == NULL)
		{
			std::cout << "Unable to optimize image %s! SDL Error: %s\n" << SDL_GetError() << std::endl;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);

		//Apply the image (BMP)
		SDL_BlitSurface(optimizedSurface, NULL, gScreenSurface, NULL);
	}

	return true;
}

void Graphics::update()
{
	//Update the surface
	SDL_UpdateWindowSurface(gWindow);
}

void Graphics::unload()
{
	//Deallocate surface
	SDL_FreeSurface(optimizedSurface);
	optimizedSurface = NULL;
}
