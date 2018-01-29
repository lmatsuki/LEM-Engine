#pragma once

#include "ISystem.h"
#include "FGraphics.h"

class SRender : public ISystem
{
public:
	SRender(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<FGraphics> graphicsFramework);
	~SRender();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<FGraphics> _graphicsFramework;
};