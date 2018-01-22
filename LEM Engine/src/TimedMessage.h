#pragma once

#include "Message.h"

// The base message struct used to be sent X time later, carries another innerMessage to be executed after specified time has elapsed.
struct TimedMessage : public Message
{
	TimedMessage(MessageType type, std::string consoleMessage, int remainingTime, std::shared_ptr<Message> innerMessage)
		: remainingTime(remainingTime), innerMessage(innerMessage), Message(type, consoleMessage)
	{

	}

	void updateRemainingTime(const int time)
	{
		remainingTime -= time;
		if (remainingTime < 0)
			remainingTime = 0;
	}

	std::shared_ptr<Message> innerMessage;
	int remainingTime;
};