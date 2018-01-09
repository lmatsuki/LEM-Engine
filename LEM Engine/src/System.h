#pragma once

#include <iostream>
#include <memory>
#include "Message.h"

class MessageBus;

class System
{
public:
	System(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	virtual ~System();

	virtual void handleMessages(Message message) = 0;

private:
	std::weak_ptr<MessageBus> _messageBus;
	std::string _systemName;
};