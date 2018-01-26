#pragma once

#include <vector>
#include <algorithm>
#include "System.h"
#include "ClockLib.h"

class TimedEvent : public System
{
public:
	TimedEvent(std::shared_ptr<MessageBus> messageBus);
	~TimedEvent();

	virtual const std::string getSystemName() override;
	void handleMessages(std::shared_ptr<Message> & message) override;
	void update() override;
	void handleTimedMessages(std::shared_ptr<TimedMessage> & message);

private:
	std::vector<std::shared_ptr<TimedMessage>> _timedEvents;
	int _lastMilliSeconds;
};