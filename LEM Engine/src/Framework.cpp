#include "Framework.h"

Framework::Framework(std::shared_ptr<MessageBus> messageBus, std::string frameworkName) : _messageBus(messageBus), _frameworkName(frameworkName)
{
	std::cout << _frameworkName << " framework ready." << std::endl;
}

Framework::~Framework()
{
	std::cout << _frameworkName << " framework shutting down." << std::endl;
}
