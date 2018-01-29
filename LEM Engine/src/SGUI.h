#pragma once

#include "ISystem.h"
#include "FGraphics.h"

class SGUI : public ISystem
{
public:
	SGUI(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<FGraphics> graphicsFramework);
	~SGUI();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<FGraphics> _graphicsFramework;
};