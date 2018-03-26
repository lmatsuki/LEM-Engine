#pragma once

#include "ISystem.h"
#include "GraphicsFramework.h"

class RenderSystem : public ISystem
{
public:
	RenderSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<GraphicsFramework> graphicsFramework);
	~RenderSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<GraphicsFramework> _graphicsFramework;
};