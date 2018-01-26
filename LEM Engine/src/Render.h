#pragma once

#include "System.h"
#include "Graphics.h"

class Render : public System
{
public:
	Render(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<Graphics> graphicsFramework);
	~Render();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<Graphics> _graphicsFramework;
};