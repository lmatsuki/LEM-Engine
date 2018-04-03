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
	std::shared_ptr<GraphicsFramework> graphicsFramework = addFramework<GraphicsFramework>();
	std::shared_ptr<InputFramework> inputFramework = addFramework<InputFramework>();


	// Add systems to the message bus
	addSystem<InputSystem>(inputFramework);
	addSystem<ConsoleSystem>();
	addSystem<RenderSystem>(graphicsFramework);
	addSystem<GUISystem>(graphicsFramework);
	addSystem<TimedEventSystem>();
	addSystem<SceneSystem>();



	// Initialize Frameworks
	if (graphicsFramework->init() != StatusCode::Success)
	{
		std::cout << "Failed to initialize Graphics Framework." << std::endl;
		return false;
	}		

	return true;
}

void MessageBus::pollMessages()
{	
	std::shared_ptr<Game> gamePtr;
	for (auto& message : _messages)
	{
		// Check that the Game pointer hasn't expired (should never happen, but keep for safety/good practice)
		gamePtr = _game.lock();
		if (gamePtr)
		{
			// Send each message to Game Logic (read-only)
			gamePtr->handleMessages(*message);
		}

		// Sends each message to every system
		for (auto& system : _systems)
		{
			system->handleMessages(message);
		}
	}

	// Delete the messages after processing
	_messages.clear();
}

void MessageBus::postMessage(const std::shared_ptr<Message> & message)
{
	_messages.push_back(message);
}

template <typename T>
std::shared_ptr<T> MessageBus::addFramework()
{
	std::shared_ptr<T> framework = std::make_shared<T>();
	//Framework * frameworkPtr = framework.get();
	//Utility::printLn("Added " + frameworkPtr->getFrameworkName() + " framework to MessageBus.");
	return std::move(framework);
}

template<typename T>
void MessageBus::addSystem()
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this())));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to the Message Bus.");
}

template <typename T, typename T2>
void MessageBus::addSystem(std::shared_ptr<T2> & framework)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), framework));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to the Message Bus.");
}

template <typename T, typename T2, typename T3>
void MessageBus::addSystem(std::shared_ptr<T2> & firstFramework, std::shared_ptr<T3> & secondFramework)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), firstFramework, secondFramework));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to the Message Bus.");
}

// Runs the update function for every system.
void MessageBus::updateSystems()
{
	for (auto& system : _systems)
	{
		system->update();
	}
}
