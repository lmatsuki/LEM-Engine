#include "Console.h"

Console::Console(std::shared_ptr<MessageBus> messageBus) : System(messageBus)
{
	std::cout << "Console system ready." << std::endl;
}

Console::~Console()
{
	std::cout << "Console system shutting down." << std::endl;
}

void Console::handleMessages(Message message)
{
	std::cout << "Console Message: " << message.consoleMessage << std::endl;
}