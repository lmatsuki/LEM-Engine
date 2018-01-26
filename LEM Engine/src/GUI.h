#pragma once

#include "System.h"
#include "Graphics.h"

class GUI : public System
{
public:
	GUI(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<Graphics> graphicsFramework);
	~GUI();

	virtual const std::string getSystemName() override;
	void handleMessages(std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<Graphics> _graphicsFramework;
};