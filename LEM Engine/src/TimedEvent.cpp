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
		_timedEvents.push_back(message);
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
	for (auto it = _timedEvents.begin(); it != _timedEvents.end(); it++)
	{
		std::shared_ptr<TimedMessage> castedEvent = std::static_pointer_cast<TimedMessage>(*it);
		switch (castedEvent->type)
		{
		case MessageType::TimedMilliSecondsEvent:
		case MessageType::TimedSecondsEvent:
			// Pass in the time
			castedEvent->updateRemainingTime(elapsedTime);
			break;
		}

		if (castedEvent->remainingTime == 0)
		{
			handleTimedMessages(castedEvent, it);
		}			
	}

	// Delete events marked toBeDeleted
	_timedEvents.erase(std::remove_if(
		_timedEvents.begin(), _timedEvents.end(), [](std::shared_ptr<Message> msg) {
		return msg->toBeDeleted;
	}), _timedEvents.end());
}

void TimedEvent::handleTimedMessages(std::shared_ptr<TimedMessage> & message, const std::vector<std::shared_ptr<Message>>::iterator & it)
{
	// Mark as deleted to remove from queue if messageBus is valid
	message->toBeDeleted = true;

	// Send event to message bus
	postMessage(message->innerMessage);
}
