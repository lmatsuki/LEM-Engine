#pragma once

#include <iostream>
#include "ISystem.h"

class SConsole : public ISystem
{
public:
	SConsole(std::shared_ptr<MessageBus> messageBus);
	~SConsole();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
};