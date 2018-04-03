#include "SceneSystem.h"

SceneSystem::SceneSystem(std::shared_ptr<MessageBus> messageBus) : ISystem(messageBus)
{
}


SceneSystem::~SceneSystem()
{
}

const std::string SceneSystem::getSystemName()
{
	return "Scene";
}

void SceneSystem::handleMessages(const std::shared_ptr<Message>& message)
{
}

void SceneSystem::update()
{
}
