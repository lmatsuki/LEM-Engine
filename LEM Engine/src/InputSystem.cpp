#include "InputSystem.h"

InputSystem::InputSystem(std::shared_ptr<MessageBus> messageBus)
	: ISystem(messageBus)
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
	
}