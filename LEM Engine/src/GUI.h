#pragma once

#include "System.h"
#include "Graphics.h"

class GUI : public System
{
public:
	GUI(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Graphics> graphicsFramework);
	~GUI();

	void handleMessages(std::shared_ptr<Message> & message);
	void update();

private:
	std::shared_ptr<Graphics> _graphicsFramework;
};