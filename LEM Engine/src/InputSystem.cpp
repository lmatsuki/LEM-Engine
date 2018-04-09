#include "InputSystem.h"

InputSystem::InputSystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<InputFramework> inputFramework, std::shared_ptr<IParserFramework> parserFramework,
	std::shared_ptr<StringToMessageTypeConverter> stringToMessageTypeConverter)
	: _inputFramework(inputFramework), _parserFramework(parserFramework), _stringToMessageTypeConverter(stringToMessageTypeConverter), ISystem(messageBus)
{
	std::cout << "データロード命令の受信を確認。" << std::endl;
	_parserFramework.get()->loadFile("Assets/Data/InputMaps.xml");
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
		// Translate key inputs here into Events (MessageTypes) and post it
		// MessageType messageType = getMessageTypeByEvent(event);
		// Message inputMsg(messageType, "Input message.");
		// postMessage(std::make_shared<Message>(inputMsg));

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