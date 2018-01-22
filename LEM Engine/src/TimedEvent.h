#pragma once

#include <vector>
#include <algorithm>
#include "System.h"
#include "Timer.h"

class TimedEvent : public System
{
public:
	TimedEvent(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Timer> timerFramework);
	~TimedEvent();

	void handleMessages(std::shared_ptr<Message> & message);
	void update();
	void handleTimedMessages(std::shared_ptr<TimedMessage> & message, const std::vector<std::shared_ptr<Message>>::iterator & it);

private:
	std::vector<std::shared_ptr<Message>> _timedEvents;
	std::shared_ptr<Timer> _timerFramework;

	int _lastMilliSeconds;
};