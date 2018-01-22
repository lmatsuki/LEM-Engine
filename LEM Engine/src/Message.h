#pragma once

#include <string>
#include <ctime>
#include "MessageType.h"

// The default message struct used by the MessageBus.
struct Message
{
	Message() {}
	Message(MessageType type, std::string consoleMessage) : type(type), toBeDeleted(false), consoleMessage(consoleMessage)
	{

	}
	virtual ~Message() {}

	MessageType type;
	bool toBeDeleted;
	std::string consoleMessage;
};