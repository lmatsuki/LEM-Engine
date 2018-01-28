#include "Render.h"

Render::Render(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<Graphics> graphicsFramework)
	: _graphicsFramework(graphicsFramework), System(messageBus)
{

}

Render::~Render()
{
	std::cout << "Render is finally shutdown." << std::endl;
}

const std::string Render::getSystemName()
{
	return "Render";
}

void Render::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
	case MessageType::CreateMainWindow:
		std::string windowName = ((StringMessage*)message.get())->dataString;
		_graphicsFramework.get()->createMainWindow(windowName);
		break;
	}
}

void Render::update()
{
	_graphicsFramework.get()->render();
}
