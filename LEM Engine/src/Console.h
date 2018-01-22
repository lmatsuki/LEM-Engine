#pragma once

#include <iostream>
#include "System.h"

class Console : public System
{
public:
	Console(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	~Console();

	void handleMessages(std::shared_ptr<Message> & message);
	void update();
};