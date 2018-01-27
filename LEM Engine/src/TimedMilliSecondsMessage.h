#pragma once

#include "TimedMessage.h"

// The message struct used to be sent X milliseconds later.
struct TimedMilliSecondsMessage : public TimedMessage
{
	TimedMilliSecondsMessage(const MessageType type, const std::string & consoleMessage, const int remainingTime, const std::shared_ptr<Message> & innerMessage)
		: TimedMessage(type, consoleMessage, remainingTime, innerMessage)
	{

	}
};