#include "STimedEvent.h"
#include "MessageBus.h"

STimedEvent::STimedEvent(std::shared_ptr<MessageBus> messageBus)
	: _lastMilliSeconds(0), ISystem(messageBus)
{
}

STimedEvent::~STimedEvent()
{
}

const std::string STimedEvent::getSystemName()
{
	return "TimedEvent";
}

void STimedEvent::handleMessages(const std::shared_ptr<Message>& message)
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

void STimedEvent::update()
{
	// Update the timer
	int elapsedTime = Clock::getTimeInMilliSeconds() - _lastMilliSeconds;
	_lastMilliSeconds = Clock::getTimeInMilliSeconds();

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

void STimedEvent::handleTimedMessages(std::shared_ptr<TimedMessage> & message)
{
	// Send event to message bus
	postMessage(message->innerMessage);

	// Mark as deleted to remove from queue if messageBus is valid
	message->toBeDeleted = true;
}
