#include "InputSystem.h"

InputSystem::InputSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<InputFramework> inputFramework)
	: _inputFramework(inputFramework), ISystem(messageBus)
{

}

InputSystem::~InputSystem()
{

}

const std::string InputSystem::getSystemName()
{
	return "Input";
}

void InputSystem::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
		//case MessageType::CreateMainWindow:
		//{
		//	std::string windowName = ((StringMessage*)message.get())->dataString;
		//	_graphicsFramework.get()->createMainWindow(windowName);
		//	break;
		//}
	}
}

void InputSystem::update()
{
	_inputFramework.get()->update();

	// Process the queue input event
	for (auto& event : _inputFramework.get()->getQueuedInputEvents())
	{
		if (event->type == SDL_QUIT)
		{
			// To be able to quit the game at any time
			Message quitMsg(MessageType::QuitGame, "Quitting game.");
			postMessage(std::make_shared<Message>(quitMsg));
		}
	}

	// Clear the input event queue
	_inputFramework.get()->clearQueuedInputEvents();
}