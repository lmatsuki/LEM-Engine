#pragma once

#include <memory>
#include <iostream>
#include "Message.h"
#include "Exception.h"

class MessageBus;

class Framework
{
public:
	Framework(std::string frameworkName);
	virtual ~Framework();

private:
	//std::weak_ptr<MessageBus> _messageBus;
	std::string _frameworkName;
};