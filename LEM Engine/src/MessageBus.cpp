#include "MessageBus.h"

MessageBus::MessageBus()
{
	std::cout << "Message Bus is created." << std::endl;
}

MessageBus::~MessageBus()
{
	std::cout << "Message Bus is destroyed." << std::endl;
}

void MessageBus::init()
{
	// ********************************************************* //
	// Control the order of construction and initialization here //
	// ********************************************************* //

	// Add frameworks to the message bus
	_frameworks.push_back(std::make_unique<Graphics>(std::shared_ptr<MessageBus>(shared_from_this()), "Graphics"));
	

	// Add systems to the message bus
	_systems.push_back(std::make_unique<Console>(std::shared_ptr<MessageBus>(shared_from_this()), "Console"));
	_systems.push_back(std::make_unique<GUI>(std::shared_ptr<MessageBus>(shared_from_this()), "GUI"));

	// Test message
	Message msg(MessageType::Console, "Testing console printing.");
	_messages.push_back(msg);
}

void MessageBus::pollMessages()
{	
	std::vector<std::unique_ptr<System>>::iterator it;
	for (Message message : _messages)
	{
		// Sends each message to every system
		for (it = _systems.begin(); it != _systems.end(); it++)
		{
			it->get()->handleMessages(message);
		}
	}

	// Delete the messages after processing
	_messages.clear();
}

void MessageBus::postMessage(Message message)
{
	_messages.push_back(message);
}
