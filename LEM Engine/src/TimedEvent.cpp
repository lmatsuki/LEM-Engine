#include "TimedEvent.h"
#include "MessageBus.h"

TimedEvent::TimedEvent(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Timer> timerFramework)
	: _timerFramework(timerFramework), _lastMilliSeconds(0), System(messageBus, systemName)
{
}

TimedEvent::~TimedEvent()
{
}

void TimedEvent::handleMessages(std::shared_ptr<Message>& message)
{
	switch (message->type)
	{
	case MessageType::TimedMilliSecondsEvent:
	case MessageType::TimedSecondsEvent:
		// Add timed events to own messages queue
		_timedEvents.push_back(std::static_pointer_cast<TimedMessage>(message));
		break;
	}
}

void TimedEvent::update()
{
	// Update the timer
	_timerFramework.get()->update();
	int elapsedTime = _timerFramework->getTimeInMilliSeconds() - _lastMilliSeconds;
	_lastMilliSeconds = _timerFramework->getTimeInMilliSeconds();

	// Update the remaining time for timed events
	for (auto & event : _timedEvents)
	{
		switch (event->type)
		{
		case MessageType::TimedMilliSecondsEvent:
		case MessageType::TimedSecondsEvent:
			// Pass in the time
			event->updateRemainingTime(elapsedTime);
			break;
		}

		if (event->remainingTime == 0)
		{
			handleTimedMessages(event);
		}
	}

	// Delete events marked toBeDeleted
	_timedEvents.erase(std::remove_if(
		_timedEvents.begin(), _timedEvents.end(), [](std::shared_ptr<TimedMessage> msg) 
	{
		return msg->toBeDeleted;
	}), _timedEvents.end());
}

void TimedEvent::handleTimedMessages(std::shared_ptr<TimedMessage> & message)
{
	// Send event to message bus
	postMessage(message->innerMessage);

	// Mark as deleted to remove from queue if messageBus is valid
	message->toBeDeleted = true;
}
