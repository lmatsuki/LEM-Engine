#include "System.h"

System::System(std::shared_ptr<MessageBus> messageBus) : _messageBus(messageBus)
{
}

System::~System()
{
}
