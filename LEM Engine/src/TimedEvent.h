#pragma once

#include <vector>
#include <algorithm>
#include "System.h"
#include "ClockLib.h"

class TimedEvent : public System
{
public:
	TimedEvent(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	~TimedEvent();

	void handleMessages(std::shared_ptr<Message> & message);
	void update();
	void handleTimedMessages(std::shared_ptr<TimedMessage> & message);

private:
	std::vector<std::shared_ptr<TimedMessage>> _timedEvents;

	int _lastMilliSeconds;
};