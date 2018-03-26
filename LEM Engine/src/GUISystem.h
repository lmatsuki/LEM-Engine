#pragma once

#include "ISystem.h"
#include "GraphicsFramework.h"

class GUISystem : public ISystem
{
public:
	GUISystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<GraphicsFramework> graphicsFramework);
	~GUISystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<GraphicsFramework> _graphicsFramework;
};