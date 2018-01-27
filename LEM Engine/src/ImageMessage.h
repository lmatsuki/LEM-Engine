#pragma once

#include "Message.h"

// Used to pass two strings (path, filename) as an event
struct ImageMessage : public Message
{
	ImageMessage(const MessageType type, const std::string & consoleMessage, const std::string & imagePath, const std::string & fileName)
		: imagePath(imagePath), fileName(fileName), Message(type, consoleMessage)
	{

	}

	const std::string imagePath;
	const std::string fileName;
};