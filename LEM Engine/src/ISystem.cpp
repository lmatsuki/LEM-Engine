#include "ISystem.h"
#include "MessageBus.h"

ISystem::ISystem(std::shared_ptr<MessageBus> messageBus) : _messageBus(messageBus)
{

}

ISystem::~ISystem()
{

}

void ISystem::postMessage(const std::shared_ptr<Message>& message)
{
	std::shared_ptr<MessageBus> messageBus = _messageBus.lock();
	if (messageBus)
	{
		messageBus->postMessage(message);
	}		
}
