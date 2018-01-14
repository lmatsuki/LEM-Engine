#include "System.h"

System::System(std::shared_ptr<MessageBus> messageBus, std::string systemName) : _messageBus(messageBus), _systemName(systemName)
{
	std::cout << _systemName << " system created." << std::endl;
}

System::~System()
{
	std::cout << _systemName << " system deleted." << std::endl;
}