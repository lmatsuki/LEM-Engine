#pragma once

#include "Message.h"

// The base message struct used to be sent X time later, carries another innerMessage to be executed after specified time has elapsed.
struct TimedMessage : public Message
{
	TimedMessage(const MessageType type, const std::string & consoleMessage, const int remainingTime, const std::shared_ptr<Message> & innerMessage)
		: remainingTime(remainingTime), innerMessage(innerMessage), toBeDeleted(false), Message(type, consoleMessage)
	{

	}

	void updateRemainingTime(const int time)
	{
		remainingTime -= time;
		if (remainingTime < 0)
			remainingTime = 0;
	}

	int remainingTime;
	const std::shared_ptr<Message> innerMessage;
	bool toBeDeleted;
};