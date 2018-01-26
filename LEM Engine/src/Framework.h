#pragma once

#include <memory>
#include <iostream>
#include "Message.h"
#include "Exception.h"
#include "StatusCode.h"

class MessageBus;

class Framework
{
public:
	Framework();
	virtual ~Framework();

	virtual const std::string & getFrameworkName() = 0;
private:
	//std::weak_ptr<MessageBus> _messageBus;
};