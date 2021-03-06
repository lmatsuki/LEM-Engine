#include "TimedEventSystem.h"
#include "MessageBus.h"

TimedEventSystem::TimedEventSystem(std::shared_ptr<MessageBus> messageBus)
	: _lastMilliSeconds(0), ISystem(messageBus)
{
}

TimedEventSystem::~TimedEventSystem()
{
}

const std::string TimedEventSystem::getSystemName()
{
	return "Timed Event";
}

void TimedEventSystem::handleMessages(const std::shared_ptr<Message>& message)
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

void TimedEventSystem::update()
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

void TimedEventSystem::handleTimedMessages(std::shared_ptr<TimedMessage> & message)
{
	// Send event to message bus
	postMessage(message->innerMessage);

	// Mark as deleted to remove from queue if messageBus is valid
	message->toBeDeleted = true;
}
