#pragma once

#include <iostream>
#include "ISystem.h"

class ConsoleSystem : public ISystem
{
public:
	ConsoleSystem(std::shared_ptr<MessageBus> messageBus);
	~ConsoleSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
};