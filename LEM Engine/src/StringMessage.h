#pragma once

#include "Message.h"

// Used to pass a single string (path, text) as an event
struct StringMessage : public Message
{
	StringMessage(MessageType type, std::string consoleMessage, std::string dataString) 
		: dataString(dataString), Message(type, consoleMessage)
	{
		
	}

	std::string dataString;
};