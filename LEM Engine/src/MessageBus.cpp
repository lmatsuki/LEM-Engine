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
	_systems.push_back(std::make_unique<Console>(std::shared_ptr<MessageBus>(shared_from_this())));

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