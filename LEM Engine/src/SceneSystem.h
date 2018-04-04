#pragma once

#include "ISystem.h"
#include "XMLParserFramework.h"

class SceneSystem : public ISystem
{
public:
	SceneSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<XMLParserFramework> xmlParserFramework);
	~SceneSystem();

	virtual const std::string getSystemName() override;
	void handleMessages(const std::shared_ptr<Message> & message) override;
	void update() override;

private:
	std::shared_ptr<XMLParserFramework> _xmlParserFramework;
};

