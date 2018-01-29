#include "SConsole.h"
#include "MessageBus.h"

SConsole::SConsole(std::shared_ptr<MessageBus> messageBus) : ISystem(messageBus)
{
	
}

SConsole::~SConsole()
{
	
}

const std::string SConsole::getSystemName()
{
	return "SConsole";
}

void SConsole::handleMessages(const std::shared_ptr<Message> & message)
{
	std::cout << "~: " << message->consoleMessage << std::endl;
}

void SConsole::update()
{

}