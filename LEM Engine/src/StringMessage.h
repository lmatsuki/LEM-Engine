#pragma once

#include "Message.h"

// Used to pass a single string (path, text) as an event
struct StringMessage : public Message
{
	StringMessage(const MessageType type, const std::string & consoleMessage, const std::string & dataString) 
		: dataString(dataString), Message(type, consoleMessage)
	{
		
	}

	const std::string dataString;
};