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
	//std::shared_ptr<Timer> timerFramework = std::make_shared<Timer>("Timer");

	// Add systems to the message bus
	addSystem<Console>();
	addSystem<Render>(graphicsFramework);
	addSystem<GUI>(graphicsFramework);
	addSystem<TimedEvent>();

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
	postMessage(std::make_shared<Message>(consoleMsg));
	Message windowMsg(MessageType::CreateMainWindow, "Creating main window.");
	postMessage(std::make_shared<Message>(windowMsg));
	StringMessage imageMsg(MessageType::LoadBackground, "Loading a background image.", "Assets/Sprites/hello_world.bmp");
	postMessage(std::make_shared<StringMessage>(imageMsg));

	std::shared_ptr<StringMessage> delayedImageMsg = std::make_shared<StringMessage>(MessageType::LoadBackground, "Loading a second background image.", "Assets/Sprites/preview.png");
	//TimedMilliSecondsMessage timedMsg(MessageType::TimedMilliSecondsEvent, "Loading a background image after 5000ms.", 5000, delayedImageMsg);
	TimedSecondsMessage timedMsg(MessageType::TimedSecondsEvent, "Loading a background image after 3 seconds.", 3, delayedImageMsg);
	postMessage(std::make_shared<TimedSecondsMessage>(timedMsg));

	//Message quitMsg(MessageType::QuitGame, "Quit application.");
	//postMessage(std::make_unique<Message>(quitMsg));

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
			_game.lock()->handleMessages(*message);
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

void MessageBus::postMessage(std::shared_ptr<Message> message)
{
	_messages.push_back(message);
}

template<typename T>
void MessageBus::addSystem()
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this())));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to MessageBus.");
}

template <typename T, typename T2>
void MessageBus::addSystem(std::shared_ptr<T2> framework)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), framework));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to MessageBus.");
}

template <typename T, typename T2, typename T3>
void MessageBus::addSystem(std::shared_ptr<T2> firstFramework, std::shared_ptr<T3> secondFramework)
{
	_systems.push_back(std::make_unique<T>(std::shared_ptr<MessageBus>(shared_from_this()), firstFramework, secondFramework));
	Utility::printLn("Added " + _systems.back()->getSystemName() + " system to MessageBus.");
}

// Runs the update function for every system.
void MessageBus::updateSystems()
{
	for (auto& system : _systems)
	{
		system->update();
	}
}
