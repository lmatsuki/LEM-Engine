#pragma once

#include "ISystem.h"

class InputSystem : public ISystem
{
public:
	InputSystem(std::shared_ptr<MessageBus> messageBus);
	~InputSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
};