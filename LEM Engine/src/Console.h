#pragma once

#include <iostream>
#include "System.h"

class Console : public System
{
public:
	Console(std::shared_ptr<MessageBus> messageBus);
	~Console();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
};