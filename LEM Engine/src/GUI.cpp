#include "GUI.h"

GUI::GUI(std::shared_ptr<MessageBus> messageBus, std::string systemName) : System(messageBus, systemName)
{
	//Exception e("Some GUI initializiation error.");
	//throw (e);

	// Initialize frameworks
	_graphicsFramework = std::make_unique<Graphics>("Graphics");
	if (!_graphicsFramework.get()->init())
		throw Exception("Error initializing Graphics Framework in GUI System.");
}

GUI::~GUI()
{
	std::cout << "GUI is finally shutdown." << std::endl;
}

void GUI::handleMessages(std::unique_ptr<Message> & message)
{
	switch (message->type)
	{
	case MessageType::CreateWindow:
		_graphicsFramework.get()->createWindow();
		break;
	case MessageType::LoadImage:		
		std::string filePath = ((StringMessage*)message.get())->dataString;
		_graphicsFramework.get()->loadImage(filePath);
		break;
	}
}

void GUI::update()
{
	_graphicsFramework.get()->render();
}