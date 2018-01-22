#pragma once

#include <iostream>
#include <memory>
#include "Message.h"
#include "StringMessage.h"
#include "TimedMilliSecondsMessage.h"
#include "TimedSecondsMessage.h"
#include "Exception.h"

class MessageBus;

class System
{
public:
	System(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	virtual ~System();

	virtual void handleMessages(std::shared_ptr<Message> & message) = 0;
	virtual void update() = 0;
	virtual void postMessage(std::shared_ptr<Message> & message);

public:
	std::weak_ptr<MessageBus> _messageBus;
	std::string _systemName;
};