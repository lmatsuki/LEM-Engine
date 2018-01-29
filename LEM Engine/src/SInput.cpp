#include "SInput.h"

SInput::SInput(std::shared_ptr<MessageBus> messageBus)
	: ISystem(messageBus)
{

}

SInput::~SInput()
{

}

const std::string SInput::getSystemName()
{
	return "SInput";
}

void SInput::handleMessages(const std::shared_ptr<Message> & message)
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

void SInput::update()
{
	
}