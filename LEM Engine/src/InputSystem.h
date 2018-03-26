#pragma once

#include "ISystem.h"
#include "InputFramework.h"

class InputSystem : public ISystem
{
public:
	InputSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<InputFramework> inputFramework);
	~InputSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<InputFramework> _inputFramework;
};