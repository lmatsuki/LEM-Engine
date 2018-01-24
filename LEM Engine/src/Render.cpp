#include "Render.h"

Render::Render(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Graphics> graphicsFramework)
	: _graphicsFramework(graphicsFramework), System(messageBus, systemName)
{

}

Render::~Render()
{
	std::cout << "Render is finally shutdown." << std::endl;
}

void Render::handleMessages(std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
	case MessageType::CreateMainWindow:
		_graphicsFramework.get()->createMainWindow();
		break;
	}
}

void Render::update()
{
	_graphicsFramework.get()->render();
}
