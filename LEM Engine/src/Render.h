#pragma once

#include "System.h"
#include "Graphics.h"
#include "Timer.h"

class Render : public System
{
public:
	Render(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Graphics> graphicsFramework, std::shared_ptr<Timer> timerFramework);
	~Render();

	void handleMessages(std::shared_ptr<Message> & message);
	void update();

private:
	std::shared_ptr<Graphics> _graphicsFramework;
	std::shared_ptr<Timer> _timerFramework;
};