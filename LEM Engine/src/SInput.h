#pragma once

#include "ISystem.h"

class SInput : public ISystem
{
public:
	SInput(std::shared_ptr<MessageBus> messageBus);
	~SInput();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;
};