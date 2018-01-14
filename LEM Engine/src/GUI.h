#pragma once

#include "System.h"
#include "Graphics.h"

class GUI : public System
{
public:
	GUI(std::shared_ptr<MessageBus> messageBus, std::string systemName);
	~GUI();

	void handleMessages(std::unique_ptr<Message> & message);
	void update();

private:
	std::unique_ptr<Graphics> _graphicsFramework;
};