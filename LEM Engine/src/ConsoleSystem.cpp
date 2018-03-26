#include "ConsoleSystem.h"
#include "MessageBus.h"

ConsoleSystem::ConsoleSystem(std::shared_ptr<MessageBus> messageBus) : ISystem(messageBus)
{
	
}

ConsoleSystem::~ConsoleSystem()
{
	
}

const std::string ConsoleSystem::getSystemName()
{
	return "Console";
}

void ConsoleSystem::handleMessages(const std::shared_ptr<Message> & message)
{
	std::cout << "~: " << message->consoleMessage << std::endl;
}

void ConsoleSystem::update()
{

}