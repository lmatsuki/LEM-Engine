#include "Console.h"
#include "MessageBus.h"

Console::Console(std::shared_ptr<MessageBus> messageBus, std::string systemName) : System(messageBus, systemName)
{
	
}

Console::~Console()
{
	
}

void Console::handleMessages(std::shared_ptr<Message> & message)
{
	std::cout << "~: " << message->consoleMessage << std::endl;
}

void Console::update()
{

}