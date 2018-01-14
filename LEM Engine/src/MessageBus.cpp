#include "MessageBus.h"

MessageBus::MessageBus()
{
	std::cout << "Message Bus is created." << std::endl;
}

MessageBus::~MessageBus()
{
	std::cout << "Message Bus is destroyed." << std::endl;
}

bool MessageBus::init()
{
	// ********************************************************* //
	// Control the order of construction and initialization here //
	// ********************************************************* //

	try
	{
		// Add frameworks to the message bus
		//_frameworks.push_back(std::make_unique<Graphics>(std::shared_ptr<MessageBus>(shared_from_this()), "Graphics"));


		// Add systems to the message bus
		_systems.push_back(std::make_unique<Console>(std::shared_ptr<MessageBus>(shared_from_this()), "Console"));
		_systems.push_back(std::make_unique<GUI>(std::shared_ptr<MessageBus>(shared_from_this()), "GUI"));

		
		// ********************************************************* //
		// Faking of messages //
		// ********************************************************* //
		// Test Console system
		Message consoleMsg(MessageType::Console, "Testing console printing.");
		postMessage(std::make_unique<Message>(consoleMsg));
		Message windowMsg(MessageType::CreateWindow, "Creating new window.");
		postMessage(std::make_unique<Message>(windowMsg));
		StringMessage imageMsg(MessageType::LoadImage, "Loading an image.", "Assets/Sprites/preview.png");
		postMessage(std::make_unique<StringMessage>(imageMsg));
	}
	catch (Exception& e)
	{
		std::cout << "** Failed to start game engine: " << std::endl << 
			"** ID: " << e.id << std::endl  <<
			"** Error: " << e.errorMessage << std::endl;
		return false;
	}

	return true;
}

void MessageBus::pollMessages()
{	
	for (auto& message : _messages)
	{
		// Sends each message to every system
		for (auto& system : _systems)
		{
			system->handleMessages(message);
		}
	}

	// Delete the messages after processing
	_messages.clear();
}

void MessageBus::postMessage(std::unique_ptr<Message> message)
{
	_messages.push_back(std::move(message));
}

// Runs the update function for every system.
void MessageBus::updateSystems()
{
	for (auto& system : _systems)
	{
		system->update();
	}
}
