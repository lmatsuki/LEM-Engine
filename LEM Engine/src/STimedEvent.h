#pragma once

#include <vector>
#include <algorithm>
#include "ISystem.h"
#include "ClockLib.h"

class STimedEvent : public ISystem
{
public:
	STimedEvent(std::shared_ptr<MessageBus> messageBus);
	~STimedEvent();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
	void handleTimedMessages(std::shared_ptr<TimedMessage> & message);

private:
	std::vector<std::shared_ptr<TimedMessage>> _timedEvents;
	int _lastMilliSeconds;
};