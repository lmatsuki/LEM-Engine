#include "GUI.h"

GUI::GUI(std::shared_ptr<MessageBus> messageBus, std::string systemName, std::shared_ptr<Graphics> graphicsFramework) 
	: _graphicsFramework(graphicsFramework), System(messageBus, systemName)
{
	//Exception e("Some GUI initializiation error.");
	//throw (e);

	// Initialize frameworks

}

GUI::~GUI()
{
	std::cout << "GUI is finally shutdown." << std::endl;
}

void GUI::handleMessages(std::unique_ptr<Message> & message)
{
	switch (message->type)
	{
	case MessageType::LoadBackground:		
		std::string filePath = ((StringMessage*)message.get())->dataString;
		_graphicsFramework.get()->loadImage(filePath);
		break;
	}
}

void GUI::update()
{
	// Render System already calls render to Graphics Framework
}