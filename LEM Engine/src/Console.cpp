#include "Console.h"
#include "MessageBus.h"

Console::Console(std::shared_ptr<MessageBus> messageBus) : System(messageBus)
{
	
}

Console::~Console()
{
	
}

const std::string Console::getSystemName()
{
	return "Console";
}

void Console::handleMessages(std::shared_ptr<Message> & message)
{
	std::cout << "~: " << message->consoleMessage << std::endl;
}

void Console::update()
{

}