#pragma once

#include "TimedMessage.h"

// The message struct used to be sent X milliseconds later.
struct TimedMilliSecondsMessage : public TimedMessage
{
	TimedMilliSecondsMessage(MessageType type, std::string consoleMessage, int remainingTime, std::shared_ptr<Message> innerMessage)
		: TimedMessage(type, consoleMessage, remainingTime, innerMessage)
	{

	}
};