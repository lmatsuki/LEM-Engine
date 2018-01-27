#pragma once

#include <string>
#include <ctime>
#include "MessageType.h"

// The default message struct used by the MessageBus.
struct Message
{
	Message() : type(MessageType::Console), consoleMessage("") {}
	Message(const MessageType type, const std::string & consoleMessage) : type(type), consoleMessage(consoleMessage)
	{

	}
	virtual ~Message() {}

	const MessageType type;
	const std::string consoleMessage;
};