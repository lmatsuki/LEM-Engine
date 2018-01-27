#pragma once

#include "TimedMessage.h"

// The message struct used to be sent X seconds later.
struct TimedSecondsMessage : public TimedMessage
{
	TimedSecondsMessage(const MessageType type, const std::string & consoleMessage, const int remainingTime, const std::shared_ptr<Message> & innerMessage)
		: TimedMessage(type, consoleMessage, remainingTime * CLOCKS_PER_SEC, innerMessage)
	{

	}
};