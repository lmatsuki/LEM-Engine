#pragma once

#include <string>
#include <memory>
#include <SDL.h>
#include "DefaultImageOrder.h"

struct ImageData
{
	ImageData(const std::string & imagePath,
			  const std::string & fileName,
			  std::unique_ptr<SDL_Rect> imagePosition = std::make_unique<SDL_Rect>(SDL_Rect{ 0, 0, 0, 0 }),
			  const int zOrder = ImageOrder::Static)
		: imagePath(imagePath),
		fileName(fileName),
		imagePosition(std::move(imagePosition)),
		zOrder(zOrder)
	{

	}

	const std::string imagePath;
	const std::string fileName;
	std::unique_ptr<SDL_Rect> imagePosition;
	const int zOrder;
	SDL_Texture * texture;
};