#include "System.h"
#include "MessageBus.h"

System::System(std::shared_ptr<MessageBus> messageBus) : _messageBus(messageBus)
{

}

System::~System()
{

}

void System::postMessage(const std::shared_ptr<Message>& message)
{
	std::shared_ptr<MessageBus> messageBus = _messageBus.lock();
	if (messageBus)
	{
		messageBus->postMessage(message);
	}		
}
