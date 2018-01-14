#include "Console.h"

Console::Console(std::shared_ptr<MessageBus> messageBus, std::string systemName) : System(messageBus, systemName)
{
	
}

Console::~Console()
{
	
}

void Console::handleMessages(std::unique_ptr<Message> & message)
{
	std::cout << "~: " << message->consoleMessage << std::endl;
}

void Console::update()
{

}