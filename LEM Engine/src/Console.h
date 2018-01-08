#pragma once

#include <iostream>
#include "System.h"

class Console : public System
{
public:
	Console(std::shared_ptr<MessageBus> messageBus);
	~Console();

	void handleMessages(Message message);
};