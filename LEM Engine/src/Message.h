#pragma once

#include <string>
#include "MessageType.h"

// The default message struct used by the MessageBus.
struct Message
{
	Message() {};

	Message(MessageType type, std::string consoleMessage)
	{
		this->type = type;
		this->consoleMessage = consoleMessage;
	}

	MessageType type;
	std::string consoleMessage;
};