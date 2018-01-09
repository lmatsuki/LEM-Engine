#pragma once

#include "System.h"

class GUI : public System
{
public:
	GUI(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	~GUI();

	void handleMessages(Message message);
};