#pragma once

#include <memory>
#include <iostream>
#include "Message.h"

class MessageBus;

class Framework
{
public:
	Framework(std::shared_ptr<MessageBus> messageBus, std::string frameworkName);
	~Framework();

	virtual void handleMessages(Message message) = 0;

private:
	std::weak_ptr<MessageBus> _messageBus;
	std::string _frameworkName;
};