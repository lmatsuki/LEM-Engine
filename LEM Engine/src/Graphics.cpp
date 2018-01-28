#include "Graphics.h"

Graphics::Graphics() : _screenWidth(800), _screenHeight(600), 
	_imageDataDict(std::make_unique<std::map<std::string, std::unique_ptr<ImageData>>>()),
	sdlTextureDict(std::make_unique<std::map<std::string, SDL_Texture*>>()), 
	sdlRectDict(std::make_unique<std::map<std::string, std::unique_ptr<SDL_Rect>>>()), gWindow(NULL),
	gRenderer(NULL), gTexture(NULL), gInputTextTexture(NULL), textColor({ 0, 0, 0, 0xFF }), gFont(NULL), _textWidth(0), _textHeight(0)	
{

}

Graphics::~Graphics()
{
	//Destroy window   
	SDL_DestroyRenderer(gRenderer);
	SDL_DestroyWindow(gWindow);
	SDL_DestroyTexture(gTexture);
	gWindow = NULL;
	gRenderer = NULL;
	gTexture = NULL;

	TTF_Quit();
	IMG_Quit();
}

const StatusCode Graphics::init()
{
	// Initialize SDL VIDEO
	if (SDL_Init(SDL_INIT_VIDEO) != 0)
	{
		std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
		return StatusCode::FailedToInitialize;
	}	

	return StatusCode::Success;
}

const std::string & Graphics::getFrameworkName()
{
	return "Graphics";
}

bool Graphics::createMainWindow(const std::string & windowName)
{
	//Create window
	gWindow = SDL_CreateWindow(windowName.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, _screenWidth, _screenHeight, SDL_WINDOW_SHOWN);
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

bool Graphics::storeImage(const std::string & filename, std::unique_ptr<ImageData> imageData)
{
	// Check that the filename doesn't exist in the dictionary	
	if ((*_imageDataDict.get())[filename])
		return false;

	// Try to load the image and create the texture
	SDL_Surface* loadedSurface = IMG_Load(imageData->imagePath.c_str());
	imageData->texture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
	if (loadedSurface == NULL || imageData->texture == NULL)
		return false;

	// Store the ImageData in the dictionary
	(*_imageDataDict.get())[filename] = std::move(imageData);	

	// Get rid of old loaded surface
	SDL_FreeSurface(loadedSurface);
	return true;
}

bool Graphics::renderImage(const std::string & filename)
{
	// Add to the list of images to render
	_renderList.push_back(filename);

	// Sort the list of images
	std::sort(_renderList.begin(), _renderList.end(),
		[&](const std::string & a, const std::string & b)
	{
		return (*_imageDataDict.get())[a]->zOrder < (*_imageDataDict.get())[b]->zOrder;
	});

	return true;
}

// Find and remove the image from the renderList by the filename.
bool Graphics::unrenderImage(const std::string & filename)
{
	auto it = std::find(_renderList.begin(), _renderList.end(), filename);
	if (it != _renderList.end())
	{
		_renderList.erase(it);
		return true;
	}		

	return false;
}

bool Graphics::loadImage(const std::string & path)
{
	//Load image at specified path
	SDL_Surface* loadedSurface = IMG_Load(path.c_str());
	if (loadedSurface == NULL)
	{
		std::cout << "Unable to load image %s! SDL_image Error: " << path.c_str() << IMG_GetError() << std::endl;
		return false;
	}
	else
	{
		//Create texture from surface pixels
		gTexture = SDL_CreateTextureFromSurface(gRenderer, loadedSurface);
		if (gTexture == NULL)
		{
			std::cout << "Unable to create texture from: " << path.c_str() << SDL_GetError() << std::endl;
			return false;
		}

		//Get rid of old loaded surface
		SDL_FreeSurface(loadedSurface);
	}

	return true;
}

void Graphics::render()
{
	//Clear screen
	SDL_RenderClear(gRenderer);

	//Render the sorted list of textures to screen
	SDL_RenderCopy(gRenderer, gTexture, NULL, NULL);
	for (auto filename : _renderList)
	{
		SDL_RenderCopy(gRenderer, (*_imageDataDict.get())[filename].get()->texture,
			NULL, (*_imageDataDict.get())[filename].get()->imagePosition.get());
	}	

	//Update screen
	SDL_RenderPresent(gRenderer);
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

	//// Load the font
	//gFont = TTF_OpenFont("lazy.ttf", 28);
	//if (gFont == NULL)
	//{
	//	std::cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
	//	return false;
	//}

	return true;
}

bool Graphics::loadText(std::string inputText)
{
	// Load the font
	gFont = TTF_OpenFont("Assets/Fonts/Roboto-Medium.ttf", 28);
	if (gFont == NULL)
	{
		std::cout << "Failed to load lazy font! SDL_ttf Error: " << TTF_GetError() << std::endl;
		return false;
	}

	if (inputText == "")
		inputText = " ";

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

void Graphics::updateScreen()
{
	SDL_RenderPresent(gRenderer);
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
