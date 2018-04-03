#pragma once

#include "ISystem.h"

class SceneSystem : public ISystem
{
public:
	SceneSystem(std::shared_ptr<MessageBus> messageBus);
	~SceneSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:

};

