#include "Console.h"

Console::Console(std::shared_ptr<MessageBus> messageBus, std::string systemName) : System(messageBus, systemName)
{
	
}

Console::~Console()
{
	
}

void Console::handleMessages(Message message)
{
	std::cout << "Console Message: " << message.consoleMessage << std::endl;
}