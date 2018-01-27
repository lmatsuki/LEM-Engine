#pragma once

#include "Message.h"
#include "ImageData.h"

// Used to pass image information (requires path, filename) as an event.
// Also specify x, y, w, h using a unique_ptr of SDL_Rect.
struct ImageMessage : public Message
{
	ImageMessage(const MessageType type, 
				 const std::string & consoleMessage, 
				 const std::string & imagePath, 
				 const std::string & fileName,
				 std::unique_ptr<SDL_Rect> imagePosition = std::make_unique<SDL_Rect>(SDL_Rect{0, 0, 0, 0}),
				 const int zOrder = ImageOrder::Static)
		: imageData(std::make_unique<ImageData>(imagePath, fileName, std::move(imagePosition), zOrder)),
		  Message(type, consoleMessage)
	{

	}

	std::unique_ptr<ImageData> imageData;
};