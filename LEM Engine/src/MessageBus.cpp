#include "MessageBus.h"
#include "Game.h"

MessageBus::MessageBus(std::shared_ptr<Game> game) : _game(game)
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

	// Create Frameworks that are shared across multiple systems
	std::shared_ptr<Graphics> graphicsFramework = std::make_shared<Graphics>("Graphics");

	// Add systems to the message bus
	addSystem<Console>("Console");
	addSystem<Render>("Render", graphicsFramework);
	addSystem<GUI>("GUI", graphicsFramework);

	// Initialize Frameworks
	if (graphicsFramework->init() != StatusCode::Success)
	{
		std::cout << "Failed to initialize Graphics Framework." << std::endl;
		return false;
	}		

	// ********************************************************* //
	// ********************* Fake messages ********************* //
	// ********************************************************* //
	Message consoleMsg(MessageType::Console, "Testing console printing.");
	postMessage(std::make_unique<Message>(consoleMsg));
	Message windowMsg(MessageType::CreateMainWindow, "Creating main window.");
	postMessage(std::make_unique<Message>(windowMsg));
	StringMessage imageMsg(MessageType::LoadBackground, "Loading a background image.", "Assets/Sprites/preview.png");
	postMessage(std::make_unique<StringMessage>(imageMsg));
	//Message quitMsg(MessageType::QuitGame, "Quit application.");
	//postMessage(std::make_unique<Message>(quitMsg));

	return true;
}

void MessageBus::pollMessages()
{	
	for (auto& message : _messages)
	{
		// Send each message to Game Logic
		_game.lock()->handleMessages(message);

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

template<typename T>
void MessageBus::addSystem(std::string systemName)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), systemName));
}

template <typename T, typename T2>
void MessageBus::addSystem(std::string systemName, std::shared_ptr<T2> framework)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), systemName, framework));
}

// Runs the update function for every system.
void MessageBus::updateSystems()
{
	for (auto& system : _systems)
	{
		system->update();
	}
}
