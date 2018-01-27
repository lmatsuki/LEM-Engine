#pragma once

#include <iostream>
#include <memory>
#include "Message.h"
#include "StringMessage.h"
#include "TimedMilliSecondsMessage.h"
#include "TimedSecondsMessage.h"
#include "ImageMessage.h"
#include "Exception.h"

class MessageBus;

class System
{
public:
	System(std::shared_ptr<MessageBus> messageBus);
	virtual ~System();

	virtual const std::string getSystemName() = 0;
	virtual void handleMessages(const std::shared_ptr<Message> & message) = 0;
	virtual void update() = 0;
	virtual void postMessage(const std::shared_ptr<Message> & message);

public:
	std::weak_ptr<MessageBus> _messageBus;
};