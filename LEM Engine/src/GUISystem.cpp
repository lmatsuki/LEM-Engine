#include "GUISystem.h"

GUISystem::GUISystem(std::shared_ptr<MessageBus> messageBus, std::shared_ptr<GraphicsFramework> graphicsFramework)
	: _graphicsFramework(graphicsFramework), ISystem(messageBus)
{
	//Exception e("Some GUISystem initializiation error.");
	//throw (e);

	// Initialize frameworks

}

GUISystem::~GUISystem()
{
	std::cout << "GUI System is finally shutdown." << std::endl;
}

const std::string GUISystem::getSystemName()
{
	return "GUI";
}

void GUISystem::handleMessages(const std::shared_ptr<Message> & message)
{
	switch (message->type)
	{
/*		case MessageType::LoadBackground:	
		{
			std::string filePath = ((StringMessage*)message.get())->dataString;
			_graphicsFramework.get()->loadImage(filePath);
			break;
		}*/		
	}
}

void GUISystem::update()
{
	// Render System already calls render to Graphics Framework
}