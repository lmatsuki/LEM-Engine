#pragma once

#include <memory>
#include <iostream>
#include <map>
#include <vector>
#include "Message.h"
#include "Exception.h"
#include "StatusCode.h"

class MessageBus;

class IFramework
{
public:
	IFramework();
	virtual ~IFramework();

	virtual const std::string & getFrameworkName() = 0;
private:
	//std::weak_ptr<MessageBus> _messageBus;
};