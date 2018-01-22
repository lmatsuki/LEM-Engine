#pragma once

#include "TimedMessage.h"

// The message struct used to be sent X seconds later.
struct TimedSecondsMessage : public TimedMessage
{
	TimedSecondsMessage(MessageType type, std::string consoleMessage, int remainingTime, std::shared_ptr<Message> innerMessage)
		: TimedMessage(type, consoleMessage, remainingTime * CLOCKS_PER_SEC, innerMessage)
	{

	}
};